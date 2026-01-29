#include <string.h>
#include "color.h"
#include "setup.h"

void loadTestCases(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf(RED "Cannot open file.\n" RESET);
        return;
    }

    int choice, val, pos, key;
    char taskDescription[255]; 

    while (fscanf(file, "%d", &choice) != EOF) {

        switch (choice) {
            case 1:
                fscanf(file, "%d", &val);
                sprintf(taskDescription, GREEN "Add %d to the head" RESET, val);
                insertAtHead(head, val);
                break;
            case 2: // insert at tail
                fscanf(file, "%d", &val);
                sprintf(taskDescription, GREEN "Add %d to the tail" RESET, val);
                insertAtTail(head, val);
                break;
            case 3: // insert at position
                fscanf(file, "%d%d", &pos, &val);
                sprintf(taskDescription, GREEN "Add %d to the position %d" RESET, val, pos);
                insertAtPosition(head, val, pos);
                break;
            case 4: // insert after key
                fscanf(file, "%d%d", &key, &val);
                sprintf(taskDescription, GREEN "Add %d after %d" RESET, val, key);
                insertAfterKeys(head, val, key);
                break;
            case 5: // insert before key
                fscanf(file, "%d%d", &key, &val);
                sprintf(taskDescription, GREEN "Add %d before %d" RESET, val, key);
                insertBeforeKeys(head, val, key);
                break;
            case 6: // Delete at head
                strcpy(taskDescription, RED "Delete head element" RESET);
                deleteAtHead(head);
                break;
            case 7: // Delete at tail
                break;
            case 8: // Delete at position
                break;
            case 9: // Delete all key
                break;
            case 10: // Delete after key
                break;
            case 11: // Delete before key
                break;
            case 0:
                printf(YELLOW "Test cases ended.\n" RESET);
                fclose(file);
                return;
            default:
                printf(RED "Invalid choice in file.\n" RESET);
                continue;
        }
        
        printf(CYAN "Task: %s\n" RESET, taskDescription);
        printList(*head);
        printf("\n");
    }

    fclose(file);
}
