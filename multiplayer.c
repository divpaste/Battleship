#include <stdio.h>
#include <stdlib.h>

// Divvi

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    
}
void gameBoard(int b1[8][8], int b2[8][8])
{
    int r, c, i;
    for (i = -1; i < 8; i++)
    {
        if (i == -1)
        {
            printf("\033[1;37mX\033[0m ");
            continue;
        }
        printf("\033[1;37m%d \033[0m", i);
    }
    printf("\t      ");
    for (i = -1; i < 8; i++)
    {
        if (i == -1)
        {
            printf("\033[1;37mX\033[0m ");
            continue;
        }
        printf("\033[1;37m%d \033[0m", i);
    }
    printf("\n");
    for (r = 0; r < 8; r++)
    {
        printf("\033[1;37m%d\033[0m", r);
        for (c = 0; c < 8; c++)
        {
            if (b1[r][c] >= 103 && b1[r][c] <= 105)
            {
                printf("\033[1;32m %d\033[0m", b1[r][c] - 100);
            }
            else if (b1[r][c] == -1)
            {
                printf("\033[1;31m M\033[0m");
            }
            else
            {
                printf("\033[1;34m ~\033[0m");
            }
        }
        printf("\t      ");
        printf("\033[1;37m%d\033[0m", r);
        for (c = 0; c < 8; c++)
        {
            if (b2[r][c] >= 103 && b2[r][c] <= 105)
            {
                printf("\033[1;32m %d\033[0m", b2[r][c] - 100);
            }
            else if (b2[r][c] == -1)
            {
                printf("\033[1;31m M\033[0m");
            }
            else
            {
                printf("\033[1;34m ~\033[0m");
            }
        }
        printf("\n");
    }
}

void loadMap1(int b1[8][8])
{
    int r, c, i;
    for (i = -1; i < 8; i++)
    {
        if (i == -1)
        {
            printf("\033[1;37mX\033[0m ");
            continue;
        }
        printf("\033[1;37m%d \033[0m", i);
    }
    printf("\n");
    for (r = 0; r < 8; r++)
    {
        printf("\033[1;37m%d\033[0m", r);
        for (c = 0; c < 8; c++)
        {
            if (b1[r][c] > 1)
            {
                printf("\033[1;32m %d\033[0m", b1[r][c]);
            }
            else
            {
                printf("\033[1;34m ~\033[0m");
            }
        }
        printf("\n");
    }
}

void loadMap2(int b2[8][8])
{
    int r, c, i;
    for (i = -1; i < 8; i++)
    {
        if (i == -1)
        {
            printf("\033[1;37mX\033[0m ");
            continue;
        }
        printf("\033[1;37m%d \033[0m", i);
    }
    printf("\n");
    for (r = 0; r < 8; r++)
    {
        printf("\033[1;37m%d\033[0m", r);
        for (c = 0; c < 8; c++)
        {
            if (b2[r][c] > 1)
            {
                printf("\033[1;32m %d\033[0m", b2[r][c]);
            }
            else
            {
                printf("\033[1;34m ~\033[0m");
            }
        }
        printf("\n");
    }
}

void scoreBoard(int *hits1, int *misses1, int *score1, int *hits2, int *misses2, int *score2)
{
    *score1 = (*hits1 * 10) - (*misses1 * 1);
    *score2 = (*hits2 * 10) - (*misses2 * 1);
    printf("\n\033[1;35m=================\033[0m \033[1;34mBATTLE\033[0m\033[1;36mFIELD\033[0m \033[1;35m====================\033[0m\n");
    printf("      \033[1;33mPlayer\033[0m \033[1;32m1\t\t\t    \033[1;33mPlayer\033[0m \033[1;31m2\033[0m\n");
    printf("     \033[1;33mScore:\033[0m \033[1;37m%03d\033[0m\t\t\t  \033[1;33mScore:\033[0m \033[1;37m%03d\033[0m\n", *score1, *score2);
    printf("\033[1;32mHits:\033[0m \033[1;37m%02d\033[0m   \033[1;31mMiss:\033[0m \033[1;37m%02d\033[0m\t      \033[1;32mHits:\033[0m \033[1;37m%02d\033[0m   \033[1;31mMiss:\033[0m \033[1;37m%02d\033[0m\n", *hits1, *misses1, *hits2, *misses2);
    printf("\033[1;35m==================================================\033[0m\n");
}

void BombFire1(int b1[8][8], int b2[8][8], int *hits1, int *misses1)
{
    int x1, y1;
    gameBoard(b1, b2);
    printf("\n\033[1;33mFire\033[0m \033[1;31mMissile\033[0m \033[1;33mat this Location:\033[0m\n");
    do
    {
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7)
            printf("\033[1;31mInvalid coordinates! Enter (0-7).\033[0m\n");
        else if (b2[x1][y1] >= 100 || b2[x1][y1] == -1)
            printf("\033[1;31mThis Spot\033[0m \033[1;37mhas already been hit!!\033[0m\n");
        else
            break;
    } while (1);

    if (b2[x1][y1] > 1)
    {
        b2[x1][y1] = b2[x1][y1] + 100;
        (*hits1)++;
    }
    else
    {
        b2[x1][y1] = -1;
        (*misses1)++;
    }
}

void BombFire2(int b1[8][8], int b2[8][8], int *hits2, int *misses2)
{
    int x1, y1;
    gameBoard(b1, b2);
    printf("\n\033[1;33mFire\033[0m \033[1;31mMissile\033[0m \033[1;33mat this Location:\033[0m\n");
    do
    {
        scanf("%d %d", &x1, &y1);
        if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7)
            printf("\033[1;31mInvalid coordinates! Enter (0-7).\033[0m\n");
        else if (b1[x1][y1] >= 100 || b1[x1][y1] == -1)
            printf("\033[1;31mThis Spot\033[0m \033[1;37mhas already been hit!!\033[0m\n");
        else
            break;
    } while (1);

    if (b1[x1][y1] > 1)
    {
        b1[x1][y1] = b1[x1][y1] + 100;
        (*hits2)++;
    }
    else
    {
        b1[x1][y1] = -1;
        (*misses2)++;
    }
}

void f_ship(int b1[8][8], int size, int count)
{
    for (int i = 0; i < count; i++)
    {   printf("\033[1;33mPlayer\033[0m \033[1;32m1\033[0m \033[1;37mBoard On!\033[0m\n");
        while (1)
        {
            loadMap1(b1);
            int x, y, dx = 0, dy = 0;
            char ch;

            printf("\n\033[1;33mShip %d\033[0m \033[1;32m(%d-cells):\033[0m\n", i + 1, size);
            printf("\033[1;37mEnter\033[0m \033[1;31mCoordinates:\033[0m\n");
            scanf("%d %d", &x, &y);
            if (x < 0 || x > 7 || y < 0 || y > 7)
            {
                printf("\033[1;31mInvalid coordinates!\033[0m\n");
                continue;
            }

            printf("\033[1;37mChoose Direction:\033[0m \033[1;31m(H/V)\033[0m\n");
            scanf(" %c", &ch);
            if (ch == 'H' || ch == 'h')
            {
                dy = 1;
            }
            else if (ch == 'V' || ch == 'v')
            {
                dx = 1;
            }
            else
            {
                printf("\033[1;31mInvalid direction!\033[0m\n");
                continue;
            }

            int valid = 1;
            for (int j = 0; j < size; j++)
                if (x + dx * j > 7 || y + dy * j > 7 || b1[x + dx * j][y + dy * j] != 0)
                    valid = 0;

            if (valid)
            {
                for (int j = 0; j < size; j++)
                    b1[x + dx * j][y + dy * j] = size;
                break;
            }
            else
            {
                printf("\033[1;31mCan't place ship there.\033[0m\n");
            }
        }
        clearScreen();
    }
}

void s_ship(int b2[8][8], int size, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\033[1;33mPlayer\033[0m \033[1;31m2\033[0m \033[1;37mBoard On!\033[0m\n");
        while (1)
        {
            loadMap2(b2);
            int x, y, dx = 0, dy = 0;
            char ch;

            printf("\n\033[1;33mShip %d\033[0m \033[1;32m(%d-cells):\033[0m\n", i + 1, size);
            printf("\033[1;37mEnter\033[0m \033[1;31mCoordinates:\033[0m\n");
            scanf("%d %d", &x, &y);
            if (x < 0 || x > 7 || y < 0 || y > 7)
            {
                printf("\033[1;31mInvalid coordinates!\033[0m\n");
                continue;
            }

            printf("\033[1;37mChoose Direction:\033[0m \033[1;31m(H/V)\033[0m\n");
            scanf(" %c", &ch);
            if (ch == 'H' || ch == 'h')
            {
                dy = 1;
            }
            else if (ch == 'V' || ch == 'v')
            {
                dx = 1;
            }
            else
            {
                printf("\033[1;31mInvalid direction!\033[0m\n");
                continue;
            }

            int valid = 1;
            for (int j = 0; j < size; j++)
                if (x + dx * j > 7 || y + dy * j > 7 || b2[x + dx * j][y + dy * j] != 0)
                    valid = 0;

            if (valid)
            {
                for (int j = 0; j < size; j++)
                    b2[x + dx * j][y + dy * j] = size;
                break;
            }
            else
            {
                printf("\033[1;31mCan't place ship there.\033[0m\n");
            }
        }
        clearScreen();
    }
}

int main()
{
    int b1[8][8]={0},b2[8][8] = {0};
    int hits1 = 0, misses1 = 0, score1 = 000;
    int hits2 = 0, misses2 = 0, score2 = 000;
    char ch;
    do{
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            b1[r][c]=0;
        }
    }
    clearScreen();
    f_ship(b1, 3, 2);
    f_ship(b1, 4, 2);
    f_ship(b1, 5, 1);
    clearScreen();
    printf("\033[1;33mThis is your\033[0m \033[1;32mLayout:\033[0m\n");
    loadMap1(b1);
    printf("\033[1;37mDo you wish to continue??\033[0m \033[1;31m(Y/N)\033[0m \n");
    scanf(" %c",&ch);
    if(ch=='Y' || ch=='y'){
        break;
    }
    }while(ch=='N');
    ch='0';
    do{
        for(int r=0;r<8;r++){
            for(int c=0;c<8;c++){
                b2[r][c]=0;
            }
        }
        clearScreen();
        s_ship(b2, 3, 2);
        s_ship(b2, 4, 2);
        s_ship(b2, 5, 1);
        clearScreen();
        printf("\033[1;33mThis is your\033[0m \033[1;32mLayout:\033[0m\n");
        loadMap1(b2);
        printf("\033[1;37mDo you wish to continue??\033[0m \033[1;31m(Y/N)\033[0m \n");
        scanf(" %c",&ch);
        if(ch=='Y' || ch=='y'){
            break;
        }
        }while(ch=='N');
    clearScreen();
    while (hits1 < 19 && hits2 < 19)
    {
        scoreBoard(&hits1, &misses1, &score1, &hits2, &misses2, &score2);
        printf("\033[1;33m[Player 1's Turn]\033[0m\n");
        BombFire1(b1, b2, &hits1, &misses1);
        printf("\n\033[1;33m[Player 2's Turn]\033[0m\n");
        BombFire2(b1, b2, &hits2, &misses2);
        clearScreen();
    }
    if (hits1 > hits2)
    {
        printf("\n            \033[1;33mGG\033[0m \033[1;33mPlayer\033[0m \033[1;32m1\033[0m, \033[1;33mWON!!\033[0m\n");
    }
    else
    {
        printf("\n            \033[1;33mGG\033[0m \033[1;33mPlayer\033[0m \033[1;31m2\033[0m, \033[1;33mWON!!\033[0m\n");
    }
    scoreBoard(&hits1, &misses1, &score1, &hits2, &misses2, &score2);
    gameBoard(b1, b2);
}
