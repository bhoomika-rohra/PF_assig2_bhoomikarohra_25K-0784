#include <stdio.h>
void encodeMessage(char message[]);
void decodeMessage(char message[]);
int main(){
    char message[200];
    int choice=0;
    while(choice!=3){
        printf("\n--- TCS Message Encoder/Decoder ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice==1){
            printf("Enter message to encode: ");
            fgets(message, sizeof(message), stdin);
            for(int i=0;message[i]!='\0';i++){
                if (message[i]=='\n'){
                    message[i]='\0';
                }    
            }
            encodeMessage(message);
        }
        else if (choice==2){
            printf("Enter message to decode: ");
            fgets(message, sizeof(message), stdin);
            for(int i=0;message[i]!='\0';i++){
                if (message[i]=='\n'){
                    message[i]='\0';
                }    
            }
            decodeMessage(message);
        }
        else if (choice==3){
            printf("exiting..");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
void encodeMessage(char message[]){
    int len=0;
    while (message[len]!='\0'){
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = message[i];
        message[i] = message[len - i - 1];
        message[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        message[i] ^= (1 << 1); 
        message[i] ^= (1 << 4); 
    }
    printf("Encoded Message: %s\n", message);
}
void decodeMessage(char message[]) {
    int len = 0;

    while (message[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        message[i] ^= (1 << 1); 
        message[i] ^= (1 << 4); 
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = message[i];
        message[i] = message[len - i - 1];
        message[len - i - 1] = temp;
    }

    printf("Decoded Message: %s\n", message);
}
