#include <iostream>
#include <string>

#define LL long long
const int N = 2e5 + 1;

struct node
{
	int cnt;
	char c;
};
node a[N];

int n;
LL res = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		int cnt;
		char c;
		std::cin >> a[i].cnt >> a[i].c;
	}	
	int tmp = 0;
	for(int i = 0, j = n-1; i < j;)
	{
		if(a[i].c != a[j].c)
		{
			//puts("abc");
			//printf("FI i = %d, j = %d, %d, %d\n", i, j, a[i].cnt, a[j].cnt);
			if(a[i].cnt < a[j].cnt)
			{
				a[j].cnt -= a[i].cnt;
				res += a[i].cnt;
				i++;
				//puts("ava");
			}
			else if(a[i].cnt == a[j].cnt)
			{
				res += a[i].cnt;
				i++, j--;
			}
			else
			{
				a[i].cnt -= a[j].cnt;
				res += a[j].cnt;
				j--;
				//puts("avd");
				//std::cout << "bbb " << a[i].cnt << ' ' << a[j].cnt;
			}
			//printf("FI i = %d, j = %d, res = %lld\n", i, j, res);
		}
		else if(a[i].c == a[j].c)
		{
			//printf("SE i = %d, j = %d, res = %lld\n", i, j, res);
			if(a[i].cnt == a[j].cnt)
			{
				i++, j--;
			}
			else
			{
				if(a[i].cnt < a[j].cnt)
				{
					a[j].cnt -= a[i].cnt;
					i++;
					while(a[i].cnt < a[j].cnt && a[i].c == a[j].c)
					{
						a[j].cnt -= a[i].cnt;
						i++;
					}
//					j--;
//					res += a[i].cnt;
				}
				else if(a[i].cnt > a[j].cnt)
				{
					//printf("a = %d, %d\n", a[i].cnt, a[j].cnt);
					a[i].cnt -= a[j].cnt;
					j--;
					//printf("a = %d, %d\n", a[i].cnt, a[j].cnt);
					while(a[i].cnt > a[j].cnt && a[i].c == a[j].c)
					{
						a[i].cnt -= a[j].cnt;
						
						j--;
					}
//					i++;
//					res += a[j].cnt;
				}
			}
			//printf("SE i = %d, j = %d, res = %lld\n", i, j, res);
		}
		//printf("END i = %d, j = %d, res = %lld\n", i, j, res);
	}
	std::cout << res << '\n';
}


