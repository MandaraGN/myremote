#include <stdio.h>
#include <string.h>

int binarySearch(char names[][100], int size, const char* target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare mid with target
        int cmp = strcmp(names[mid], target);
        if (cmp == 0) {
            return mid; // Target found
        }
        if (cmp < 0) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);
    
    char names[n][100];
    printf("Enter %d names (one per line):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort the names for binary search
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[100];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    char target[100];
    printf("Enter the name to search for: ");
    scanf("%s", target);

    int result = binarySearch(names, n, target);
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found.\n", target);
    }

    return 0;
}