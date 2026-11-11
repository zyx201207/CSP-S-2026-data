#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
	}
int n,m,a[500050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n,cmp);
	cout<<a[0];
	return 0;
	}
