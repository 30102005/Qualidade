#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

// Estrutura para representar uma tarefa
typedef struct Task {
    char name[MAX_NAME_LEN];
    int priority;
    struct Task* next;
} Task;

// Função para criar uma nova tarefa
Task* create_task(const char* name, int priority) {
    // Verificar se o nome é válido e a prioridade não é negativa
    if (name == NULL || name[0] == '\0' || priority < 0) {
        printf("Invalid task parameters: name is empty or priority is invalid\n");
        return NULL;
    }

    Task* new_task = (Task*)malloc(sizeof(Task));
    if (new_task == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Usando snprintf para garantir que a string seja corretamente copiada e terminada
    snprintf(new_task->name, MAX_NAME_LEN, "%s", name);
    new_task->priority = priority;
    new_task->next = NULL;
    return new_task;
}

// Função para adicionar uma tarefa na lista
void add_task(Task** head, Task* new_task) {
    if (new_task == NULL) {
        printf("Error: Attempt to add a null task\n");
        return;
    }

    if (*head == NULL) {
        *head = new_task;
    } else {
        Task* last_task = *head;
        while (last_task->next != NULL) {
            last_task = last_task->next;
        }
        last_task->next = new_task;
    }
}

// Função para imprimir todas as tarefas
void print_tasks(Task* head) {
    if (head == NULL) {
        printf("No tasks to display\n");
        return;
    }

    Task* current = head;
    while (current != NULL) {
        printf("Task: %s, Priority: %d\n", current->name, current->priority);
        current = current->next;
    }
}

// Função para liberar a memória das tarefas
void free_tasks(Task* head) {
    Task* current = head;
    Task* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Task* task_list = NULL;

    // Adicionando tarefas à lista
    Task* task1 = create_task("Task 1", 1);
    Task* task2 = create_task("Task 2", 2);
    Task* task3 = create_task("Task 3", 3);

    if (task1 && task2 && task3) {
        add_task(&task_list, task1);
        add_task(&task_list, task2);
        add_task(&task_list, task3);

        // Imprimindo as tarefas
        print_tasks(task_list);

        // Liberando a memória das tarefas
        free_tasks(task_list);
    } else {
        printf("Failed to create one or more tasks\n");
    }

    return 0;
}