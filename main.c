#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *filename, const char *key) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Creating output file
    char outputFile[256];
    snprintf(outputFile, sizeof(outputFile), "%s.secure", filename);

    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error creating output file");
        fclose(file);
        return;
    }

    int keyLen = strlen(key);
    int i = 0;
    char ch;

    // Encrypt/Decrypt using XOR
    while ((ch = fgetc(file)) != EOF) {
        fputc(ch ^ key[i % keyLen], outFile);
        i++;
    }

    printf("\n✅ Process Completed! Encrypted/Decrypted file: %s\n", outputFile);

    fclose(file);
    fclose(outFile);
}

int main() {
    char filename[100], key[50];
    int choice;

    printf("\n🔒 SecureFile - File Encryption & Decryption Tool\n");
    printf("-------------------------------------------------\n");

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter secret key: ");
    scanf("%s", key);

    printf("\nChoose an option:\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        encryptDecryptFile(filename, key);
    } else {
        printf("❌ Invalid choice! Exiting...\n");
    }

    return 0;
}
