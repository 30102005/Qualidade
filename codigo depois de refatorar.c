#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

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
	strncpy(new_task->name, name, MAX_NAME_LEN - 1);
	new_task->name[MAX_NAME_LEN - 1] = '\0'; // Garantir o tC)rmino da string
	new_task->priority = priority;
	new_task->next = NULL;
	return new_task;
}

// FunC'C#o para verificar se a lista estC! vazia
int is_empty(Task* head) {
	return head == NULL;
}

// FunC'C#o para encontrar o C:ltimo nC3 da lista
Task* find_last_task(Task* head) {
	Task* temp = head;
	while (temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}

// FunC'C#o para adicionar uma tarefa ao final da lista
void add_task(Task** head, const char* name, int priority) {
	Task* new_task = create_task(name, priority);
	if (new_task == NULL) {
		return;
	}

	if (*head == NULL) {
		*head = new_task;
		return;
	}

	Task* last_task = find_last_task(*head);
	last_task->next = new_task;
}

// FunC'C#o para deletar uma tarefa pela string do nome
void delete_task(Task** head, const char* name) {
	if (is_empty(*head)) {
		printf("No tasks to delete\n");
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

// FunC'C#o para imprimir todas as tarefas
void print_tasks(Task* head) {
	if (is_empty(head)) {
		printf("No tasks to display\n");
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
