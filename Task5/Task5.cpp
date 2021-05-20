#include <iostream>
using namespace std;
int main()
{
		int x = 5;
		int f = 0;
		__asm {
			mov eax, x
			push eax
			call fact
			pop eax
			mov f, eax
			jmp l_end
		fact:
			push esi
				mov esi, esp
				add esi, 8
				push edx
				mov eax, [esi]
				or eax, eax
				jnz fact1
				inc eax
				jmp fact_end
		fact1:
			cmp eax, 1
				je fact_end
				mov edx, eax
				dec eax
				push eax
				call fact
				pop eax
				mul edx
		fact_end:
			mov[esi], eax
				pop edx
				pop esi
				ret
		l_end:
		}
		cout << f << endl;
	}


