#include <stdio.h>
#include <conio.h>
void show();
void userGute();
void Logic();
int validate();
int winningLogic();
void reset();
char arr[3][3];
int indexs[9][3] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
int main()
{
    int userInput;
    int player=1;
    int result;
    int count=0;
    int play=1;
    int playTime=0;
    
    while(1)
    {
        if(playTime > 0)
        {
            printf("Press 1 to Play Again : ");
            reset();
            scanf("%d",&play);
            player = 1;
            count=0;
        }
        if(play != 1) break;
        
        while(play == 1)
        {
            clear();
            show();
            player=!player;
            player ? printf("player-2 truns....\n"):printf("player-1 truns....\n");
            userGute();
            scanf("%d",&userInput);
            int value = validate(userInput);
            if(value == 1)
            {
                player =! player;
                printf("value already Exists!!\n");
                continue;
            }
            if(userInput >=0 && userInput <= 9)
            {
                Logic(userInput,player);
                result = winningLogic();
                count++;
                playTime++;
                if(result == 1)
                {
                    clear();
                    show();
                    printf("Player %d wins!!  \n",result);
                    break;
                }
                else if(result == 2){
                    clear();
                    show();
                    printf("Player %d wins!!  \n",result);
                    break;
                    
                }else{
                    if(count == 9)
                    {
                        clear();
                        show();
                        printf("match draws !! \n");
                        break;
                    }
                }
            }else{
                printf("wrong input!!! \n");
                player=!player;
                continue;
            }
        }
    }
    return 0;
}

void show(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] == '\0')
            {
                printf("[    ]");
            }else{
                printf("[  %c ]",arr[i][j]);
                
            }
        }
        printf("\n");
    }
}
void userGute(){
    printf("Enter input 1 to 9: ");
}
void Logic(int userInput,int player){
    
    userInput = userInput - 1;
    int row = indexs[userInput][0];
    int col = indexs[userInput][1];
    arr[row][col] = player ? '0' : 'X';
}
int validate(int userInput){
    userInput = userInput - 1;
    int row = indexs[userInput][0];
    int col = indexs[userInput][1];
    (arr[row][col] == 'X' || arr[row][col] == '0')? 1: 0;
}
int winningLogic()
{
    if((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') ||
       (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X') ||
       (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[0][2] == 'X') ||
       (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X') ||
       (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X') ||
       (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X') ||
       (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') ||
       (arr[2][0] == 'X' && arr[1][1] == 'X' && arr[0][2] == 'X') 
    )
    {
        return 1;
    }
    else if((arr[0][0] == '0' && arr[0][1] == '0' && arr[0][2] == '0') ||
            (arr[1][0] == '0' && arr[1][1] == '0' && arr[1][2] == '0') ||
            (arr[2][0] == '0' && arr[2][1] == '0' && arr[0][2] == '0') ||
            (arr[0][0] == '0' && arr[1][0] == '0' && arr[2][0] == '0') ||
            (arr[0][1] == '0' && arr[1][1] == '0' && arr[2][1] == '0') ||
            (arr[0][2] == '0' && arr[1][2] == '0' && arr[2][2] == '0') ||
            (arr[0][0] == '0' && arr[1][1] == '0' && arr[2][2] == '0') ||
            (arr[2][0] == '0' && arr[1][1] == '0' && arr[0][2] == '0') 
    )
    {
        return 2;
        
    }else{
        
        return 0;
    }
}
void reset()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            arr[i][j] = '\0';
        }
    }
}
void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
















