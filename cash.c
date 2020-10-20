#include <stdio.h>
#include <cs50.h>
#include <math.h>


int get_input(void);
void min_coins_needed(int n);


int main(void)
{
    int i = get_input();

    //printf("%i\n",i);
    
    min_coins_needed(i);
}





int get_input(void)
{
    float change_due;

    do
    {
        change_due = get_float("change owed:");
    }
        while (change_due < 0);

    int cents = round(change_due * 100);

    return cents;

    //printf("%i\n", penny_change_due);
}



void min_coins_needed(int n)
{
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    int num_qu = n / quarter;
    int remain_1 = n % quarter;
    int num_dime = remain_1 / dime;
    int remain_2 = remain_1 % dime;
    int num_nick = remain_2 / nickel;
    int remain_3 = remain_2 % nickel;
    int num_pen = remain_3 / penny;
    int remain_4 = remain_3 % penny;
    
    int min_coins = num_qu + num_dime + num_nick + num_pen;
    
    printf("%i\n", min_coins);
    
    //printf("%i quarters, %i dimes, %i nickels and %i pennies, with %i remaining", num_qu, num_dime, num_nick, num_pen, remain_4);
}
