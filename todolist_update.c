#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 10
#define MAX_LIST 100
#define MAX_PASSWORD_LENGHT 8

int i, numread;
//Creates a stucture List which contains a name and the various task on the list.
struct List{
    char task[MAX_LIST];
    char date[MAX_LENGTH];
};

int numtask = 0;//Crates a global variable numtask that keeps track of the number of task entered by the user.

int validitycheckint(int numread, int x){//To check if the input vaiable is actually a integer number
            if(numread!=1){
                printf("The value entered is not valid.\n");
                printf("Enter a valid value.\n");
                scanf("%*[^\n]");//Discards the input if condition holds .
            }

}

//Function to add tasks to the list.
void addtask(struct List tasks[], int taskcount){

    struct List newtask;

    printf("Enter task\n");

    scanf("\n%[^\n]", newtask.task);//Add the number oof tasks requested by the user
    tasks[numtask] = newtask;//Increases the number of notes by 1.
    numtask++;

    printf("Task added successfully.\n");

}

//Function to view the list
void viewlist(struct List tasks[], int taskcount){
    if(numtask == 0 ){//Checks if there are actually any current task before displaying.
        printf("You have no tasks in the todo List\n");//Displays this statement if the list is empty
    }
    else{
        for( i = 1 ; i <= numtask ; i++){
               printf("%d. %s\n", i, tasks[i-1].task);//Displays each task
           };
    }
}

//Function to delete tasks from the list.
void deletetask(struct List tasks[], int taskcount, int index){
    if (numtask == 0) {//Displays no task found if the user hadn't previously inputed any tasks.
        printf("No tasks found.\n");
        return;
    }

    do{
    printf("Enter the index of the task you want to delete: ");
    numread = scanf("%d", &index);
    validitycheckint(numread, index);
    }while(numread == 0);

    if (index < 1 || index > numtask) {//Checks if the notes's index requested for is actually in the range of existing notes
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i <= numtask - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (numtask)--;//Reduces the number of notes by 1.
    printf("Note deleted successfully!\n");
}

//Function to save a created password
void savePassword(const char *password) {
    FILE *file = fopen("pass.txt", "w");//opens the file in write mode
    if (file == NULL) {//Checks if the file exists
        fprintf(stderr, "Error opening file for writing.\n");
        return 0;
    }

    fprintf(file, "%s", password);
    fclose(file);
}

//Function to create a password
void createPassword() {
    char password[MAX_LENGTH];

    //Prompts the user to enter the first password
    printf("Enter a password (up to %d characters): ", MAX_LENGTH);
    scanf("%s", password);
    savePassword(password);
    printf("Password created and saved successfully!\n");//Returns status statement.
}

//Function to verify entered password
int verifyPassword(const char *password) {
    char storedPassword[MAX_LENGTH];
    FILE *file = fopen("pass.txt", "r");//Opens the file in read mode

    //Checks if the file exists or contains a value
    if (file == NULL) {
        printf("First time using this application!");
        createPassword();
    }

    //Compares any password input to that stores in the file
    if(strcmp(password, storedPassword) == 1){
        printf("Incorrect password!");
        exit(1);//Exists if the user inputs an incorrect password.
    }

}

int main(){
    char listname[MAX_LENGTH];
    char name[MAX_LENGTH];
    const char password[MAX_LENGTH];

    printf("----Welcome to the Todo List Application!!----\n");

    int option, index;

    int x;
    //Checks for the validity of x.
    do{
            r:
    printf("Is this your first time using the application(1 for yes or 0 for no)?");
    numread = scanf("%d", &x);
    validitycheckint(numread, x);//Calls the validity check function for integers.
    }while(numread==0);

    if( x<0 || x>1){//Checks if the user entered an invalid response
        printf("Invalid response!\n");
        goto r;
    }


    if(x == 1){//Calls the createPassword function for new users.
            printf("Please, Enter your name.\n");
            scanf("%s", &name);
            createPassword();//Function call.
    }
    else{
        //Verifies password input for returning users.
        //Tells the user the max number of characters the password may contain.
            printf("Enter your %d characters password\n", MAX_LENGTH);
            scanf("%s", &password);
            verifyPassword(password);//Function call.
    }

    printf("Hi %s, Enter the name of your List.\n", name);
    scanf("%s", &listname);


    do{
    //Displays the various options.
    printf("\n");
    printf("----MENU----\n");
    printf("1. Add new task\n");
    printf("2. view List\n");
    printf("3. Delete task\n");
    printf("4. Exit\n");

    //Prompts user to enter an option.
    do{
            //Checks for the validity of the option input.
    printf("What operation do you want to perform on List %s?\n", listname);
    numread = scanf("%d", &option);
    validitycheckint(numread, option);//Function call.
    }while(numread == 0);

    struct List tasks[MAX_LENGTH];//Declares structure list
    int taskcount = 0;

    switch (option){
        case 1:
            addtask(tasks, taskcount);//Calls the addtask function
        break;
        case 2:
            printf("%s List\n",listname );
            viewlist(tasks, taskcount);//Calls the viewlist function
        break;
        case 3:
            deletetask(tasks, taskcount, index);//Calls the delete task function
        break;
        case 4:
            printf("Exiting...\n");//Exits
            printf("Thank you for using my Application!!\n");
        break;
        default:
            if( option < 1 || option > 4){//If invalid option entered prompts user to enter another one.
                printf("Invalid choice. Make another one.");
                goto s;
            };
    }
    system("pause");
    }while( option != 4 );
    return 0;
}



