#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y)
{
	if(x > y) return true;
	else return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	cout << a[m-1];
	return 0;
}
