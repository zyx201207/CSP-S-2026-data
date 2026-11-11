#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
bool flag[N];
int b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m;
	cin >> n >> m;
//	for(int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	 } 
//	
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = i ; j <= n; j++)
//		{
//			if(flag[a[j]] == true)
//			{
//				for(int k=1; k <= j; k++)
//				{
//					flag[k] = false;
//				} 
//			}
//			else
//			{
//				flag[a[j]] == true;
//			}
//		}
//		for(int j = 1; j <= m; j++)
//		{
//			if(flag[j] == true)
//			{
//				b[j]++;
//			}
//		}
//	} 
	for(int i = 1; i <= m - 1; i++)
	{
//		cout << b[i] << ' ' ;
		cout << 0  << ' '; 
	}
	cout << n;
	return 0;
 } 
