#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 10

int i, numread;
//Creates a stucture List which contains a name and the various task on the list.
struct List{
    char task[MAX_LIST];
    char tasknum[MAX_LENGTH];
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
               printf("%d. %s\n", tasks[i-1].tasknum, tasks[i-1].task);//Displays each task
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
    validitycheckint(numread, index);//Checks if the input for index is an integer value.
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

int main(){
    //Declare the variables to hold the user and list name.
    char listname[MAX_LENGTH];
    char name[MAX_LENGTH];

    printf("----Wlcome to the Todo List Application!!----\n");
    printf("Please, Enter your name.\n");
    scanf("%s", &name);

    printf("Hi %s, Enter the name of your List.\n", name);
    scanf("%s", &listname);

    int option, index;

    do{
    //Displays the various options
    do{
    s:
    printf("\n");
    printf("----MENU----\n");
    printf("1. Add new task\n");
    printf("2. view List\n");
    printf("3. Delete task\n");
    printf("4. Exit\n");
    printf("What operation do you want to perform on List %s?\n", listname);
    numread = scanf("%d", &option);
    validitycheckint(numread, option);//Checks if the input for option is an integer value.
    }while(numread == 0);

    struct List tasks[MAX_LENGTH];//Declare a variable tasks.
    int taskcount = 0;//Sets the initial number of tasks to zero.

    switch (option){
        case 1:
            addtask(tasks, taskcount);//Calls the addtask function.
        break;
        case 2:
            printf("%s List\n",listname );
            viewlist(tasks, taskcount);//Calls the viewlist function
        break;
        case 3:
            deletetask(tasks, taskcount, index);//Calls the deletetask function
        break;
        case 4:
            
            printf("Exiting...\n");
            printf("Thank you for using my Application!!\n");
        break;
        default:
            if( option < 1 || option > 4){//Displays an error message if the requested option is not within range
                printf("Invalid choice. Make another one.");
                goto s;
            };
    }
    system("pause");//Allows the user to view the output before running another instance of the code
    }while( option != 4 );
    return 0;
}



