#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct book{
    char name[50];
    float price;
    char author[50];
};

struct user{
    char username[20];
    char password[20];
};

void create_account();
void login();
void buy_books();
void checkout(struct book cart[], int cart_count);

int main(){
    int choice;
    printf("-----------------------Book Store-----------------------\n");
    printf("========================================================\n");
    printf("Login or Create an account to continue.\n");
    printf("Select an option:\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        create_account();
        break;
    case 2:
        login();
        break;
    default:
        printf("Invalid option!\n");
        break;
    }
    return 0;
}

void create_account(){
    struct user user, exist;
    FILE *fp;

    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);

    fp = fopen("users.txt", "r");
    if(fp != NULL){
        while(fscanf(fp, "%s %s", exist.username, exist.password) != EOF){
            if(strcmp(user.username, exist.username) == 0){
                printf("Username already exists!\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    fp = fopen("users.txt", "a");
    if(fp != NULL){
        fprintf(fp, "%s %s\n", user.username, user.password);
        fclose(fp);
        printf("Account created successfully!\n");
    } else {
        printf("Error opening file!\n");
    }
}

void login(){
    struct user input, check;
    FILE *fp;
    int found = 0;

    printf("Enter username: ");
    scanf("%s", input.username);
    printf("Enter password: ");
    scanf("%s", input.password);

    fp = fopen("users.txt", "r");
    if(fp == NULL){
        printf("No users found! Please create an account first.\n");
        return;
    }

    while(fscanf(fp, "%s %s", check.username, check.password) != EOF){
        if(strcmp(input.username, check.username) == 0 && strcmp(input.password, check.password) == 0){
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(found == 1){
        printf("Login successful!\n");
        buy_books();
    } 
    else {
        printf("Invalid username or password!\n");
    }
}

void buy_books(){
    struct book b[]={
        {"Harry Potter", 500.0, "J.K. Rowling"},
        {"The Hobbit", 300.0, "J.R.R. Tolkien"},
        {"1984", 400.0, "George Orwell"},
        {"To Kill a Mockingbird", 350.0, "Harper Lee"},
        {"Hamlet", 250.0, "William Shakespeare"},
        {"Macbeth", 270.0, "William Shakespeare"},
        {"The Great Gatsby", 320.0, "F. Scott Fitzgerald"},
        {"Pride and Prejudice", 280.0, "Jane Austen"},
        {"The Catcher in the Rye", 330.0, "J.D. Salinger"},
        {"The Alchemist", 290.0, "Paulo Coelho"}
    };

    int n = sizeof(b)/sizeof(b[0]);

    struct book cart[50];
    int cart_count = 0;
    int option;

    while(1){
        printf("\nBook Store Menu:\n");
        printf("1. Search by name\n2. Search by author\n3. View all books\n4. Proceed to Checkout\nSelect an option: ");
        scanf("%d", &option);
        getchar();

        if(option == 1){
            char name[50];
            printf("Enter book name: ");
            fgets(name, sizeof(name), stdin);
            for(int i=0; name[i]!='\0'; i++){
                if(name[i]=='\n'){ 
                    name[i]='\0'; break; 
                }
            }
            int match = 0;
            for(int i=0;i<n;i++){
                if(strcasecmp(b[i].name, name)==0){
                    printf("Added to cart: %s by %s, Price: %.2f\n", b[i].name, b[i].author, b[i].price);
                    cart[cart_count++] = b[i];
                    match = 1;
                    break;
                }
            }
            if(match == 0){
                printf("Book not found!\n");
            }

        } 
        else if(option == 2){
            char author[50];
            printf("Enter author name: ");
            fgets(author, sizeof(author), stdin);
            for(int i=0; author[i]!='\0'; i++){
                if(author[i]=='\n'){ 
                    author[i]='\0'; 
                    break; 
                }
            }

            int matchCount = 0;
            int indices[50];  

            for(int i=0; i<n; i++){
                if(strcasecmp(b[i].author, author) == 0){
                    printf("%d. %s by %s, Price: %.2f\n", matchCount+1, b[i].name, b[i].author, b[i].price);
                    indices[matchCount] = i;  // store index of book
                    matchCount++;
                }
            }

            if(matchCount == 0){
                printf("No books found by this author!\n");
            } 
            else {
                printf("Select a book number to add to cart: ");
                int choice; 
                scanf("%d", &choice);

                if(choice >= 1 && choice <= matchCount){
                    cart[cart_count++] = b[indices[choice-1]];
                    printf("Added to cart: %s by %s \n", b[indices[choice-1]].name, b[indices[choice-1]].author);
                } else {
                    printf("Invalid selection!\n");
                }
            }
        }

        else if(option == 3){
            printf("Available books:\n");
            for(int i=0;i<n;i++){
                printf("%d. %s by %s, Price: %.2f\n", i+1, b[i].name, b[i].author, b[i].price);
            }
            printf("Select a book number to add to cart: ");
            int opt; 
            scanf("%d",&opt);
            if(opt>=1 && opt<=n){
                cart[cart_count++] = b[opt-1];
                printf("Added to cart: %s by %s\n", b[opt-1].name, b[opt-1].author);
            } 
            else {
                printf("Invalid number!\n");
            }

        } 
        else if(option == 4){
            if(cart_count == 0){
                printf("Your cart is empty!\n");
            } 
            else {
                checkout(cart, cart_count);
            }
            return;
        } 
        else {
            printf("Invalid option!\n");
        }
    }
}

void checkout(struct book cart[], int cart_count){
    printf("\n--- Checkout ---\n");
    float total=0;
    printf("----------------Order summary----------------\n");
    for(int i=0;i<cart_count;i++){
        printf("%d. %s by %s, Price: %.2f\n", i+1, cart[i].name, cart[i].author, cart[i].price);
        total += cart[i].price;
    }
    printf("Total: %.2f\n", total);

    printf("Select Payment Method:\n");
    printf("1. Cash on Delivery\n2. Mobile Banking\n3. Card Payment\n");
    int method;
    scanf("%d", &method);

    if(method == 1){
        printf("Order placed successfully with Cash on Delivery! Please pay %.2f Taka while delivery\n",total);
    } 
    else if(method == 2){
        char number[20], pin[6];
        printf("Select your Mobile Banking Provider:\n");
        printf("1. bKash\n2. Nagad\n3. Rocket\n");
        int provider; 
        scanf("%d",&provider);

        printf("Enter Number: "); 
        scanf("%s",number);

        if(strlen(number)!=11 || number[0]!='0'||number[1]!='1'){
            printf("Invalid number!\n"); return;
        }
        printf("Enter PIN: "); 
        scanf("%s",pin);

        if((provider==1 && strlen(pin)!=5) || (provider!=1 && strlen(pin)!=4)){
            printf("Invalid PIN!\n"); return;
        }
        printf("Payment successful via Mobile Banking!\n");

    } 
    else if(method == 3){
        int cardType;
        char card[20], expiry[10], cvv[5];

        printf("Select Card Type:\n");
        printf("1. Debit Card\n2. Credit Card\n");
        scanf("%d", &cardType);

        if(cardType != 1 && cardType != 2){
            printf("Invalid card type!\n");
            return;
        }

        printf("Enter Card Number (16 digits): ");
        scanf("%s", card);
        if(strlen(card) != 16){
            printf("Invalid card number! Must be 16 digits.\n");
            return;
        }

        printf("Enter Expiry Date (MM/YY): ");
        scanf("%s", expiry);
        if(strlen(expiry) != 5 || expiry[2] != '/'){
            printf("Invalid expiry format! Use MM/YY.\n");
            return;
        }

        printf("Enter CVV (3 digits): ");
        scanf("%s", cvv);
        if(strlen(cvv) != 3){
            printf("Invalid CVV!\n");
            return;
        }

        if(cardType == 1){
            printf("Payment successful via Debit Card!\n");
        } else {
            printf("Payment successful via Credit Card!\n");
        }
    }

    else {
        printf("Invalid method!\n");
        return;
    }

    printf("Your payment of %.2f was successful!\n", total);
}
