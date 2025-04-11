#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for(int i = 0; i < MAX_TASKS; i++){
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i = 0; i < MAX_TASKS; i++){
        if(tasks[i] != nullptr){
            delete[] tasks[i];
            tasks[i] = nullptr;
        }
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int count = 0;
    while(str[count] != '\0'){
        count += 1;
    }
    return count;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size >= 32){
        throw std::out_of_range("size must be under 32");
    }
    else{
        int charCount = 0;
        while(task[charCount] != '\0'){
            charCount++;
        }

        tasks[size] = new char[charCount+1];
        string_copy(tasks[size], task);
        size++;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(index >= 0 && index < size){
        for(int i = index; i<size-1; i++){
            tasks[i] = tasks[i+1];
        }
        delete[] tasks[size-1] ;
        tasks[size-1] = nullptr;
        size -= 1;
    }
    else{
        std::range_error("index value is wrong");
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    if(count > 0 && count <= 32){
        return const_cast<const char**>(tasks);
    }
    return nullptr;
}