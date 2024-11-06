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

// FunC'C#o para criar uma nova tarefa
Task* create_task(const char* name, int priority) {
	if (name == NULL || priority < 0) {
		printf("Invalid task parameters\n");
		return NULL;
	}

	Task* new_task = (Task*)malloc(sizeof(Task));
	if (new_task == NULL) {
		printf("Memory allocation failed\n");
		return NULL;
	}

	// Usando strncpy para evitar buffer overflow
	strncpy(new_task->name, name, MAX_NAME_LEN - 1);
	new_task->name[MAX_NAME_LEN - 1] = '\0'; // Garantir que a string esteja terminada
	new_task->priority = priority;
	new_task->next = NULL;
	return new_task;
}

// FunC'C#o para adicionar uma tarefa na lista
void add_task(Task** head, Task* new_task) {
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

// FunC'C#o para imprimir todas as tarefas
void print_tasks(Task* head) {
	Task* current = head;
	while (current != NULL) {
		printf("Task: %s, Priority: %d\n", current->name, current->priority);
		current = current->next;
	}
}

// FunC'C#o para liberar a memC3ria das tarefas
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

	// Adicionando tarefas C  lista
	add_task(&task_list, create_task("Task 1", 1));
	add_task(&task_list, create_task("Task 2", 2));
	add_task(&task_list, create_task("Task 3", 3));

	// Imprimindo as tarefas
	print_tasks(task_list);

	// Liberando a memC3ria das tarefas
	free_tasks(task_list);

	return 0;
}
