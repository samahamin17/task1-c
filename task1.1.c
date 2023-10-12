#include

struct User {
char username[20];
char password[20];
};

void registerUser(struct User *users, int *userCount) {
if (*userCount >= 10) {
printf("Maximum number of users reached.
");
return;
}

printf("Enter username: ");
scanf("%s", users[*userCount].username);

printf("Enter password: ");
scanf("%s", users[*userCount].password);

(*userCount)++;
printf("Registration successful!
");
}

int loginUser(struct User *users, int userCount) {
char username[20], password[20];

printf("Enter username: ");
scanf("%s", username);

printf("Enter password: ");
scanf("%s", password);

for (int i = 0; i < userCount; i++) {
if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
printf("Login successful!
");
return 1;
}
}

printf("Invalid username or password.
");
return 0;
}

int main() {
struct User users[10];
int userCount = 0;
int loggedIn = 0;

while (!loggedIn) {
int choice;
printf("1. Register
");
printf("2. Login
");
printf("3. Exit
");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
registerUser(users, &userCount);
break;
case 2:
loggedIn = loginUser(users, userCount);
break;
case 3:
printf("Exiting...
");
exit(0);
default:
printf("Invalid choice.
");
break;
}
}

// Rest of your program logic goes here

return 0;
}
