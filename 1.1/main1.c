#include <stdio.h>
#include <string.h>

const int N = 1000;
int lowbit(int x){
	return x&(-x);
}

void change(int c[], int posion, int value, int len){
    while(posion <= len)
    {
        c[posion] += value;
        posion += lowbit(posion);
    }
}

int sum(int c[], int n)
{
    int answer = 0;
    while(n>0)
    {
        answer += c[n];
        n -= lowbit(n);
    }
    return answer;
}

int main(void){
	int n;
	int c[N];
	while(~scanf("%d", &n))
	{
		memset(c, 0, sizeof(c));
		int x;
		int answer = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &x);
			change(c, x, 1, n);
			answer += i -sum(c, x);
		}
		printf("%d\n", answer);
		printf("------\n");
	}
	return 0;
}

