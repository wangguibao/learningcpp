/**
 * rwlock.cpp
 * Use std::shared_mutex, std::shared_lock and std::lock_guard to simulate the
 * behavior of rwlock
 *
 * Note that std::shared_mutex requires C++17
 */
#include <iostream>
#include <thread>
#include <shared_mutex>

const int THREADS = 5;
const int DATASIZE = 15;
const int ITERATIONS = 10000;

typedef struct {
    int thread_num;
    std::thread thread_id;
    int updates;
    int reads;
    int interval;
} thread_t;

typedef struct {
    std::shared_mutex mutex;
    int data;
    int updates;
} data_t;

thread_t threads[THREADS];
data_t data[DATASIZE];

void thread_routine(thread_t& thread) {
    int element = 0;
    int repeats = 0;

    for (int i = 0; i < ITERATIONS; ++i) {
        if ((i % thread.interval) == 0) {
            std::lock_guard<std::shared_mutex> lock(data[element].mutex);

            data[element].data = thread.thread_num;
            data[element].updates++;
            thread.updates++;

        } else {
            std::shared_lock<std::shared_mutex> lock(data[element].mutex);

            thread.reads++;
            if (data[element].data == thread.thread_num) {
                repeats++;
            }

        }

        ++element;
        if (element >= DATASIZE) {
            element = 0;
        }
    }

    std::cout << "Thread " << thread.thread_num
            << " found unchanged elements " << repeats << "times"
            << std::endl;
}

int main()
{
    unsigned int seed = time(NULL);
    printf("seed = %d\n", seed);

    int thread_updates = 0;
    int data_updates = 0;

    for (int i = 0; i < DATASIZE; ++i) {
        data[i].data = 0;
        data[i].updates = 0;
    }

    for (int i = 0; i < THREADS; ++i) {
        threads[i].thread_num = i;
        threads[i].updates = 0;
        threads[i].reads = 0;
        threads[i].interval = rand_r(&seed) % 71;
        threads[i].thread_id = std::thread(thread_routine, std::ref(threads[i]));
    }

    for (int i = 0; i < THREADS; ++i) {
        threads[i].thread_id.join();

        thread_updates += threads[i].updates;
        printf("Thread %02d: interval %d, updates %d, reads %d\n",
               i,
               threads[i].interval,
               threads[i].updates,
               threads[i].reads);
    }

    for (int i = 0; i < DATASIZE; ++i) {
        data_updates += data[i].updates;
        printf("Data %d: value %d, updates %d\n",
               i,
               data[i].data,
               data[i].updates);
    }

    return 0;
}
