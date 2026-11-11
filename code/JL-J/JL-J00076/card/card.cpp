#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int a[N];
// n -> 2, 3, 5 m  -> 1 2
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf("%d %d",&n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	} 
	return 0;
}
