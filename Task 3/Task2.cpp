#include <stdio.h>

int main()
{
    int result = -1, x; // final result & input var
    scanf_s("%i", &x);
    __asm
    {
        mov edx, x
        mov ebx, 1
        xor eax, eax
        cmp edx, 3
        jl exit_
        cmp edx, 15
        jg exit_
        cycle_ :
            xor ecx, ecx
            mov ecx, ebx
            imul ecx, ecx
            sub ecx, ebx
            sub ecx, 6
            add eax, ecx
            cmp ebx, edx
            je exit_2
            add ebx, 1
            jmp cycle_
            exit_2 :
        mov result, eax
            exit_ :
    }
    printf("Result=%d\n", result);   // showing result, if input is out of bounds - then output equals -1
    return 0;
}
