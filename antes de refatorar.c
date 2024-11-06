#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char name[100];
    int priority;
    struct Task* next;
} Task;

Task* create_task(const char* name, int priority) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    if (new_task == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->next = NULL;
    return new_task;
}

void add_task(Task** head, const char* name, int priority) {
    Task* new_task = create_task(name, priority);
    if (new_task == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = new_task;
        return;
    }

    Task* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_task;
}

void delete_task(Task** head, const char* name) {
    if (*head == NULL) {
        printf("No tasks to delparaarate\n");
        return;
    }

    Task* temp = *head;
    Task* prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void print_tasks(Task* head) {
    if (head == NULL) {
        printf("No tasks to dislay\n");
        return;
    }

    Task* temp = head;
    while (temp != NULL) {
        printf("Task: %s, Priority: %d\n", temp->name, temp->priority);
        temp = temp->next;
    }
}

int main() {
    Task* task_list = NULL;

    add_task(&task_list, "Task 1", 1);
    add_task(&task_list, "Task 2", 2);
    add_task(&task_list, "Task 3", 3);
    print_tasks(task_list);

    delete_task(&task_list, "Task 2");
    print_tasks(task_list);

    return 0;
}
