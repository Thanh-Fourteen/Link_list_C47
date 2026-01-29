#include "insert.cpp"
#include "delete.cpp"
#include "color.h"
#include "loadTestCase.cpp"

void menu() {
	printf("%s+----------------------- Menu -----------------------+%s\n", GREEN, RESET);
	printf("%s| %-50s |%s\n", RED, "0. Exit", RESET);
	printf("%s| %-50s |%s\n", CYAN, "1. Add to the beginning of the list", RESET);
	printf("%s| %-50s |%s\n", CYAN, "2. Add to the end of the list", RESET);
	printf("%s| %-50s |%s\n", CYAN, "3. Insert an element at a position", RESET);
	printf("%s| %-50s |%s\n", CYAN, "4. Add an element after a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "5. Add an element before a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "6. Remove the first element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "7. Remove the last element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "8. Remove an element at a position", RESET);
	printf("%s| %-50s |%s\n", CYAN, "9. Remove a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "10. Remove an element after a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "11. Remove an element before a specific element", RESET);
	printf("%s| %-50s |%s\n", YELLOW, "12. Print the linked list", RESET);
	printf("%s| %-50s |%s\n", YELLOW, "13. Load test cases from file", RESET);
	printf("%s+----------------------------------------------------+%s\n", GREEN, RESET);
}

int main() {
	menu();
	int choice;
	Node *head = NULL;
	do {
		menu();
		printf("Your choice: ");
		scanf("%d", &choice);
		int value, position, key, key_value;
		char filename[100];

		switch (choice) {
			case 1:// Insert at Head
				printf("Enter the value to add: ");
				scanf("%d", &value);
				insertAtHead(&head, value);
				break;

			case 2:// Insert at Tail
				printf("Enter the value to add: ");
				scanf("%d", &value);
				insertAtTail(&head, value);
				break;
			case 3: // Insert at position
				printf("Enter the position: ");
				scanf("%d", &position);
				printf("Enter the value to add: ");
				scanf("%d", &value);
				insertAtPosition(&head, value, position);
				break;

			case 4: // Add after a specific element
				printf("Enter the value to add: ");
				scanf("%d", &value);
				printf("Enter key: ");
				scanf("%d", &key);
				insertAfterKeys(&head, value, key);
				break;
			case 5: // Add before a specific element
				printf("Enter the value to add: ");
				scanf("%d", &value);
				printf("Enter key: ");
				scanf("%d", &key);
				insertBeforeKeys(&head, value, key);
				break;
			case 6: // Delete the first element
				deleteAtHead(&head);
				printf("List after deleting the first element:\n");
				printList(head);
				break;
			case 7: // Delete the last element
				deleteAtTail(&head);
				printf("List after deleting the last element:\n");
				printList(head);
				system("pause");
				break;
			case 8: // Delete at position
				deleteAtPosition(&head, position);
				printf("List after deleting an element at a position:\n");
				printList(head);
				system("pause");
				break;
			case 9: // Delete all occurrences of a value
				deleteAllKeys(&head, key);
				printf("List after deleting a specific element:\n");
				printList(head);
				system("pause");
				break;
			case 10: // Delete after a specific element
				deleteAfterKeys(&head, key);
				printf("List after deleting an element after a specific element:\n");
				printList(head);
				system("pause");
				break;
			case 11: // Delete before a specific element
				deleteBeforeKeys(&head, key);
				printf("List after deleting an element before a specific element:\n");
				printList(head);
				system("pause");
				break;
			case 12:
				printf("Current linked list: ");
				printList(head);
				break;
		
			case 13: // Load test cases from file
	            printf("Enter the test case filename: ");
	            scanf("%s", filename);
	            loadTestCases(&head, filename);
	            printf("Test cases loaded successfully.\n");
	            system("pause");
				break;

			default:
				printf("Error choice!\n");
				break;
		}

	} while (choice != 0);

	freeList(&head);
	return 0;
}



