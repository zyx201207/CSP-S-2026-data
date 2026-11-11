#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	
 }
	for(int i=1;i<=n;i++)
	{
		a[i] and a[n];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
	return 0;
}
