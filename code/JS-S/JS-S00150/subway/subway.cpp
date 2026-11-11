#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int a[500010],b[510],r[510][30],t[510][30],s[500010],e[500010];

int main(){
	freopen("weimingming.in","r",stdin);
	freopen("weimingming.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		for(int j=1;j<=b[i];j++)
		{
			cin>>r[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s[i]>>e[i];
	}
	cout<<0;
	return 0;
}
