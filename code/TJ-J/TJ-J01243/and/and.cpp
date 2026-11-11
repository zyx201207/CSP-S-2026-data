#include <bits/stdc++.h>
using namespace std;
int n,m,b[100000],cnt;
bool r(int y)
{
	if(y % 2 == 0) return 0;
	for(int i =1;i <= n;i++)
	{
		b[i] = y % 2;
		y %= 2;
	}
}
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <=n;i++)
	{
		cin >> a[i];
		a[i] = r(a[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == a[i-1])
		{
			cnt+=a[i];
		}
	} 
	cout << cnt;
	return 0;
} 
