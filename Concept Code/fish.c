#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*this is the only global variable that I am using here, kindly excuse this. 
this was the format we were taught in the SI session.
this also makes the flow of my code much easier and error free.*/
struct Grid {  
      char data;
      struct Grid *up;
      struct Grid *down;
      struct Grid *left;
      struct Grid *right;
      struct Grid *upLeft;
      struct Grid *upRight;
      struct Grid *downLeft;
      struct Grid *downRight;
};


/*
function: void postions(int[])
input: integer array containing the initial positions of the player and the AI
return: none
purpose: generates a random initial positions in the boundry 1's of the grid for the player and the AI.
*/
void positions(int pos[2]){
    int p = (int)rand() % 21; 
    int a = (int)rand() % 21;
    while(p == a){
        a = rand() % 21;
    }
    int indexes[20] = {0,1,2,3,4,5,6,11,12,17,18,23,24,29,30,31,32,33,34,35};
    pos[0] = indexes[p-1];
    pos[1] = indexes[a-1];
    
}
/*
function: void display(Grid)
input: (Board, Game Board that needs to be printed)
return: none
purpose: to display the game board in a neat formatted way.
*/
void display(struct Grid *Board){
    int k = 1;
    printf(" | 0 1 2 3 4 5\n");
    printf(" |------------");
    for(int i=0; i<36; ++i){
        if((i+1) % 6 == 0){
            if(i!=35){
                printf("%c \n%d| ", Board[i].data, k);
                k++;
            }
            else{
                printf("%c \n", Board[i].data);
            }
        }
        else{
            if(i==0){
                printf("\n0| %c ", Board[i].data); 
            }
            else{
                printf("%c ", Board[i].data);
            }
        }
    }
}

/*
function: int mover(char[], int, int[], Grid*)
input: (char mv[], to store the name of the move), (int step, the numbe of moves to make), (int pos[], current positions of the players), 
       (Board, Game Board that needs to be modified)
return: int, integer that shows the new positions or that an invalid input has been given.
purpose: to perform board movements as requested by the player 
*/
int mover(char mv[20], int step, int pos[2], struct Grid* Board){
    struct Grid* temp = &Board[pos[0]];
    int i = 0; 
    int flag = 1; //validity of the move
    int newPos = pos[0];
    if(strcmp(mv, "UP")==0){
        while(i<step){
            temp = temp->up;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 6;
                i++;
            }
        }
    }
    else if(strcmp(mv, "DOWN")==0){
        while(i<step){
            temp=temp->down;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 6;
                i++;
            }
        }
    }
    else if(strcmp(mv, "LEFT")==0){
        while(i<step){
            temp=temp->left;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 1;
                i++;
            }
        }
    }
    else if(strcmp(mv, "RIGHT")==0){
        while(i<step){
            temp=temp->right;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 1;
                i++;
            }
        }
    }
    else if(strcmp(mv, "UPLEFT")==0){
        while(i<step){
            temp=temp->upLeft;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 7;
                i++;
            }
        }
    }
    else if(strcmp(mv, "UPRIGHT")==0){
        while(i<step){
            temp=temp->upRight;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 5;
                i++;
            }
        }
    }
    else if(strcmp(mv, "DOWNLEFT")==0){
        while(i<step){
            temp=temp->downLeft;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 5;
                i++;
            }
        }
    }
    else if(strcmp(mv,"DOWNRIGHT")==0){
        while(i<step){
            temp=temp->downRight;
            if(temp==NULL || temp->data=='A' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 7;
                i++;
            }
        }
    }
    else{
        flag = -1;
    }
 
    if(flag == 1){
        Board[pos[0]].data='.';
        return newPos;
    }
    return -1;
}

/*
function: int mover2(char[], int, int[], Grid*)
input: (char mv[], to store the name of the move), (int step, the numbe of moves to make), (int pos[], current positions of the players), 
       (Board, Game Board that needs to be modified)
return: int, integer that shows the new positions or that an invalid input has been given.
purpose: to perform board movements as requested by the AI
*/
int mover2(char mv[20], int step, int pos[2], struct Grid* Board){
    struct Grid* temp = &Board[pos[1]];
    int i = 0; 
    int flag = 1; //validity of the move
    int newPos = pos[1];
    if(strcmp(mv, "UP")==0){
        while(i<step){
            temp = temp->up;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 6;
                i++;
            }
        }
    }
    else if(strcmp(mv, "DOWN")==0){
        while(i<step){
            temp=temp->down;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 6;
                i++;
            }
        }
    }
    else if(strcmp(mv, "LEFT")==0){
        while(i<step){
            temp=temp->left;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 1;
                i++;
            }
        }
    }
    else if(strcmp(mv, "RIGHT")==0){
        while(i<step){
            temp=temp->right;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 1;
                i++;
            }
        }
    }
    else if(strcmp(mv, "UPLEFT")==0){
        while(i<step){
            temp=temp->upLeft;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 7;
                i++;
            }
        }
    }
    else if(strcmp(mv, "UPRIGHT")==0){
        while(i<step){
            temp=temp->upRight;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos -= 5;
                i++;
            }
        }
    }
    else if(strcmp(mv, "DOWNLEFT")==0){
        while(i<step){
            temp=temp->downLeft;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 5;
                i++;
            }
        }
    }
    else if(strcmp(mv,"DOWNRIGHT")==0){
        while(i<step){
            temp=temp->downRight;
            if(temp==NULL || temp->data=='P' || temp->data=='.'){
                flag = -1;
                break;
            }
            else 
            {
                newPos += 7;
                i++;
            }
        }
    }
 
    if(flag == 1){
        Board[pos[1]].data='.';
        return newPos;
    }
    return -1;
}

/*
function: void initialize(Grid*)
input: (Board, Game Board that needs to be modified)
return: none
purpose: to initialize the game board, and make each element point to its 8 neighbours in the 8 directions of the octagon.
*/
void initialize(struct Grid* Board){

    for(int i = 0; i < 36; i++) {
        if(i==0){
            // printf("test");
            Board[i].data ='1';
            Board[i].up = NULL;
            Board[i].down = &Board[i+6];
            Board[i].left = NULL;
            Board[i].right = &Board[i+1];
            Board[i].upLeft = NULL;
            Board[i].upRight = NULL;
            Board[i].downLeft = NULL;
            Board[i].downRight = &Board[i+6];
        }
        else if(i==5){
            // printf("test");
            Board[i].data ='1';
            Board[i].up = NULL;
            Board[i].down = &Board[i+6];
            Board[i].left = &Board[i-1];
            Board[i].right = NULL;
            Board[i].upLeft = NULL;
            Board[i].upRight = NULL;
            Board[i].downLeft = &Board[i+5];
            Board[i].downRight = NULL;
        }
        else if(i==30){
            // printf("test");
            Board[i].data ='1';
            Board[i].up = &Board[i-6];
            Board[i].down = NULL;
            Board[i].left = NULL;
            Board[i].right = &Board[i+1];
            Board[i].upLeft = NULL;
            Board[i].upRight = &Board[i-5];
            Board[i].downLeft = NULL;
            Board[i].downRight = NULL;
        }
        else if(i==35){
            Board[i].data ='1';
            Board[i].up = &Board[i-6];
            Board[i].down = NULL;
            Board[i].left = &Board[i-1];
            Board[i].right = NULL;
            Board[i].upLeft = &Board[i-7];
            Board[i].upRight = NULL;
            Board[i].downLeft = NULL;
            Board[i].downRight = NULL;
        }
        else if(i>0 && i<5){
            Board[i].data ='1';
            Board[i].up = NULL;
            Board[i].down = &Board[i+6];
            Board[i].left = &Board[i-1];
            Board[i].right = &Board[i+1];
            Board[i].upLeft = NULL;
            Board[i].upRight = NULL;
            Board[i].downLeft = &Board[i+5];
            Board[i].downRight = &Board[i+7];
        }
        else if(i>30 && i<35){
            Board[i].data ='1';
            Board[i].up = &Board[i-6];
            Board[i].down = NULL;
            Board[i].left = &Board[i-1];
            Board[i].right = &Board[i+1];
            Board[i].upLeft = &Board[i-7];
            Board[i].upRight = &Board[i-5];
            Board[i].downLeft = NULL;
            Board[i].downRight = NULL;
        }
        else if(i%6==0){
            Board[i].data ='1';
            Board[i].up = &Board[i-6];
            Board[i].down = &Board[i+6];
            Board[i].left = NULL;
            Board[i].right = &Board[i+1];
            Board[i].upLeft = NULL;
            Board[i].upRight =  &Board[i-5];
            Board[i].downLeft = NULL;
            Board[i].downRight = &Board[i+7];
        }
        else if((i+1)%6==0){
            Board[i].data ='1';
            Board[i].up = &Board[i-6];
            Board[i].down = &Board[i+6];
            Board[i].left = &Board[i-1];
            Board[i].right = NULL;
            Board[i].upLeft = &Board[i-7];
            Board[i].upRight = NULL;
            Board[i].downLeft = &Board[i+5];
            Board[i].downRight = NULL;
        }
        else{
            if((i==14)||(i==15)||(i==20)||(i==21)){
                Board[i].data = '3';
            }
            else{
                Board[i].data = '2';
            }
            Board[i].up = &Board[i-6];
            Board[i].down = &Board[i+6];
            Board[i].left = &Board[i-1];
            Board[i].right = &Board[i+1];
            Board[i].upLeft = &Board[i-7];
            Board[i].upRight = &Board[i-5];
            Board[i].downLeft = &Board[i+5];
            Board[i].downRight = &Board[i+7];
        }
    
    }

}


/*
function: int getPoints(int)
input: (pos, variable that stores the position the player/AI moved from)
return: int, the number of points that needs to be rewarded for the move.
purpose: to perform board movements as requested by the player,
*/
int getPoints(int pos){
    if((pos>=0 && pos<=5) || (pos%6)==0 || (pos+1)%6==0 || (pos>=30 && pos<=35)){
        return 1;
    }
    else if((pos>=7 && pos<=10) || (pos-1)%6==0 || (pos+2)%6==0 || (pos>=25 && pos<=28)){
        return 2;
    }
    return 3;
}

/*
function: int endGame(Grid*, int)
input:  (int pos, current positions of the players), (Board, Game Board that needs to be checked)
return: integer that shows whether the player in pos can make any more moves or not.
purpose: to check whether the player can make any more moves. 
*/
int endGame(struct Grid* Board, int pos){
    struct Grid* temp = &Board[pos];
    int flag = 1;
    if((temp->up)==NULL || (temp->up->data)=='A' || (temp->up->data)=='.'){
        if((temp->down)==NULL || (temp->down->data)=='A' || (temp->down->data)=='.'){
            if((temp->left)==NULL || (temp->left->data)=='A' || (temp->left->data)=='.'){
                if((temp->right)==NULL || (temp->right->data)=='A' || (temp->right->data)=='.'){
                    if((temp->upLeft)==NULL || (temp->upLeft->data)=='A' || (temp->upLeft->data)=='.'){
                        if((temp->upRight)==NULL || (temp->upRight->data)=='A' || (temp->upRight->data)=='.'){
                            if((temp->downLeft)==NULL || (temp->downLeft->data)=='A' || (temp->downLeft->data)=='.'){
                                if((temp->downRight)==NULL || (temp->downRight->data)=='A' || (temp->downRight->data)=='.'){
                                    flag = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // printf("\nFLAG\n%d",flag);
    return flag;
}

/*
function: int main()
input: -
return: -
purpose: contains whole control of the game.
*/
int main() {
    //Building the Grid 1
    int player_points; //vaiable to store total points scored by the human player
    int ai_points; //variable to store total points scored by the AI
    srand(time(NULL));
    char ch;
    int pos[2]; //variable to store the current positions of the player and the AI
    char player_move[20]; //variable to store the name of the move made by the player 
    int player_count;
    char ai_move[20]; //variable to store the name of the move made by the AI
    const char m[8][20] = {"UP", "DOWN", "LEFT", "RIGHT", "DOWNLEFT", "DOWNRIGHT", "UPLEFT", "UPRIGHT"};
    int ai_count; 
    int ai_index;
    int return_value;
    int ai_return_value;
    int pFlag = -1;

    struct Grid *Board = (struct Grid *) malloc(36 * sizeof(struct Grid));
    printf("\n\nWelcome to the game, Hey That's my Fish!\n\n");
    initialize(Board);
    printf("This is the game board\n\n");
    display(Board);
    positions(pos);
    printf("\nThe position of the player 1 is (%d, %d)\n",pos[0]/6,pos[0]%6);
    printf("\nThe position of the player 2 is (%d, %d)\n\n",pos[1]/6, pos[1]%6);

    Board[pos[0]].data = 'P';
    Board[pos[1]].data = 'A';
    printf("\n");
    display(Board);
    player_points = 0;
    ai_points = 0;
    //the players play until first play with each other until one of them can't make moves anymore
    while(endGame(Board, pos[0])==1 && endGame(Board, pos[1])==1){  
        
        player_points += getPoints(pos[0]);
        
        printf("\n\nPlayer A please enter your move : "); //Ask input from user
        scanf("%s %d", player_move, &player_count); //scan input
        printf("\n%s %d\n", player_move, player_count); 
        return_value = mover(player_move, player_count, pos, Board); //make changes accoding to input
        while(return_value == -1) { //if input value is not valid ask again
            printf("\nInvalid move try again!\n");
            scanf("%s %d", player_move, &player_count);
            return_value = mover(player_move, player_count, pos, Board);
            printf("\n");
        }
        pos[0] = return_value;
        printf("\n\nThe new positions are:\n");
        printf("Player 1's position is (%d, %d)\n",pos[0]/6,pos[0]%6); //updated coordinates of player
        printf("AI's position is (%d, %d)\n\n",pos[1]/6, pos[1]%6); //current coodinates of ai
        Board[pos[0]].data = 'P';  
        Board[pos[1]].data = 'A';
        display(Board);

        printf("\nPlayer Points: %d", player_points);
        printf("\nAI Points: %d", ai_points);


        printf("\n\nAI's move\n\n");
        ai_points += getPoints(pos[1]);
        ai_count = 1; // makes 1 step moves for efficiency code 
        ai_index = rand() % (7 - 0 + 1) + 0; 
        strcpy(ai_move, m[ai_index]); //AI selects a random directions
        ai_return_value = mover2(ai_move, ai_count, pos, Board); //AI moved 1 step in random direction 
        while(ai_return_value == -1) { //search until valid move is found
            ai_count = 1;
            ai_index = rand() % (7 - 0 + 1) + 0;
            strcpy(ai_move, m[ai_index]);
            ai_return_value = mover2(ai_move, ai_count, pos, Board);
        }
        printf("\n%s %d\n", ai_move, ai_count); //valid move
        pos[1] = ai_return_value;
        printf("\n\nThe new positions are:\n");
        printf("Player 1's position is (%d, %d)\n",pos[0]/6,pos[0]%6); //current coordinates of player
        printf("AI's position is (%d, %d)\n\n",pos[1]/6, pos[1]%6); //updated coordinates of ai
        Board[pos[0]].data = 'P';
        Board[pos[1]].data = 'A';
        display(Board);

        printf("\nPlayer Points: %d", player_points);
        printf("\nAI Points: %d", ai_points);
        
        
        
        if(endGame(Board, pos[0])==-1){ //check if player can make any more moves
            printf("\n\nPlayer 1 is out of turns");
            pFlag = 0;
            break;
        } 
        else if(endGame(Board, pos[1])==-1){ //check if AI can make any more moves
            printf("AI is out of turns");
            pFlag = 1;
            break;
        }
    }
    //check which player can still make moves, and make them make moves until they have no where to go. Apologies for the repetitive code.
    if(pFlag == 1){
        while(endGame(Board, pos[0])==1){
            player_points += getPoints(pos[0]);
            printf("\n\nPlayer A please enter your move : ");
            scanf("%s %d", player_move, &player_count);
            printf("\n%s %d\n", player_move, player_count);
            return_value = mover(player_move, player_count, pos, Board);
            while(return_value == -1) {
                printf("\nInvalid move try again!\n");
                scanf("%s %d", player_move, &player_count);
                return_value = mover(player_move, player_count, pos, Board);
                printf("\n");
            }
            pos[0] = return_value;
            printf("\n\nThe new positions are:\n");
            printf("Player 1's position is (%d, %d)\n",pos[0]/6,pos[0]%6);
            printf("AI's position is (%d, %d)\n\n",pos[1]/6, pos[1]%6);
            Board[pos[0]].data = 'P';
            Board[pos[1]].data = 'A';
            display(Board);

            printf("\nPlayer Points: %d", player_points);
            printf("\nAI Points: %d", ai_points);
            if(endGame(Board, pos[0])==-1){
                printf("\n\nPlayer 1 is out of turns\n");
                pFlag = 0;
                break;
            }
        } 
    }
    else if(pFlag == 0){
        while(endGame(Board, pos[1])==1){
            printf("\n\nAI's move\n\n");
            ai_points += getPoints(pos[1]);
            ai_count = 1; // change this to 1 move 
            ai_index = rand() % (7 - 0 + 1) + 0;
            strcpy(ai_move, m[ai_index]);
            ai_return_value = mover2(ai_move, ai_count, pos, Board);
            while(ai_return_value == -1) {
                ai_count = 1;
                ai_index = rand() % (7 - 0 + 1) + 0;
                strcpy(ai_move, m[ai_index]);
                ai_return_value = mover2(ai_move, ai_count, pos, Board);
            }
            printf("\n%s %d\n", ai_move, ai_count);
            pos[1] = ai_return_value;
            printf("\n\nThe new positions are:\n");
            printf("Player 1's position is (%d, %d)\n",pos[0]/6,pos[0]%6);
            printf("AI's position is (%d, %d)\n\n",pos[1]/6, pos[1]%6);
            Board[pos[0]].data = 'P';
            Board[pos[1]].data = 'A';
            display(Board);

            printf("\nPlayer Points: %d\n", player_points);
            printf("\nAI Points: %d\n", ai_points);

            if(endGame(Board, pos[1])==-1){
                printf("\nAI is out of turns\n");
                pFlag = 1;
                break;
            }
        }
        
    }
    

    printf("\n\nGame Over\n\n");
    //Displaying Total Points
    printf("\n\nPoints:\n\n");
    printf("\nPlayer Points: %d\n\n", player_points); 
    printf("\nAI Points: %d\n\n", ai_points);
    //Checking who won based on the points scored by each player.
    if(player_points > ai_points){
        printf("\n\nPlayer 1 won\n\n");
    }
    else if(ai_points > player_points){
        printf("\n\nAI won\n\n");
    }
    else{
        printf("\n\nGame Draw\n\n");   
    }
    
    return 0;
}

