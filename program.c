/*
Navn: Marcelino Patrick Pini
Email: mpini21@student.aau.dk
Gruppe: Gruppe 8
Studieretning: Software
*/

#include <stdio.h>
#include <math.h>

void scan_data(char *operator_p, double *operand_p);
void do_next_op(char operator, double operand, double *akkumulator_p);
void run_calculator(char operator, double akkumulator);
int checkIfBinary(char operator);

int main(void){
    double akkumulator = 0.0;
    double operand;
    char operator;

    while(operator != 'q'){
        scan_data(&operator, &operand);
        do_next_op(operator, operand, &akkumulator);
        run_calculator(operator, akkumulator);
    }
}

/* Venter på brugerens input */
void scan_data(char *operator_p, double *operand_p){
    printf("\nEnter operator, and an optional operand: ");
    scanf(" %c", operator_p);

    if(checkIfBinary(*operator_p)){
        scanf(" %lf", operand_p);
    } else {
        *operand_p = 0.0;
    }
}

/* Beregner naeste trin alt efter operatoren og vaerdien laegges tilbage i akkumulatoren */
void do_next_op(char operator, double operand, double *akkumulator_p){
    switch(operator)
    {
        case '+':
            *akkumulator_p += operand;
            break;
        case '-':
            *akkumulator_p -= operand;
            break;
        case '*':
            *akkumulator_p *= operand;
            break;
        case '/':
            *akkumulator_p /= (!operand ? 1 : operand);
            break;
        case '^':
            *akkumulator_p = pow(*akkumulator_p, operand);
            break;
        case '#':
            *akkumulator_p = (*akkumulator_p > 0 ? sqrt(*akkumulator_p) : *akkumulator_p);
            break;
        case '%':
            *akkumulator_p *= -1;
            break;
        case '!':
            *akkumulator_p = 1 / *akkumulator_p;
            break;
        default:
            break;
    }
}

/* Udskriver resultat alt efter operatoren */
void run_calculator(char operator, double akkumulator){
    if(operator == 'q'){
        printf("Final result is %lf\n", akkumulator);
    } else {
        printf("Result so far is %lf", akkumulator);
    }
}

/* Tjekker hvis operatoren er binaer */
int checkIfBinary(char operator){
    if(operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^') return 1;
    return 0;
}