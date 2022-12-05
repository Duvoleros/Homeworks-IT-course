#include <stdio.h>

int main()
{
    int x; // input var
    int result; // final result
    scanf_s("%d", &x);
    __asm
    {
        mov eax, x
        cmp eax, 10      // checking or number > 10
        jg bigger      // jg > sign, label name
        cmp eax, 10       // checking or number < 10
        jl smaller     // jl < sign, label name
        cmp eax, 10      // checking or number = 10
        je equal       // jl = sign, label name
    bigger :
        mov ebx, eax
        imul ebx, 2
        mov edx, eax
        add edx, 2
        sub ebx, edx
        jmp exit_
    smaller :
        mov ebx, eax
        imul ebx, 3
        add ebx, 150
        jmp exit_
    equal :
        mov ebx, 9 //(x+10)^2/25 =|x=10|= 15^2/5^2 = 9
        jmp exit_
    exit_ :
        mov result, ebx
    }
    printf("Result = %d\n", result);   // showing result
}
