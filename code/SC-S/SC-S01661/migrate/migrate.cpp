#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=2e6+5,M=1e5+5;
const long long Z=2e18+5;
int c,t,cnt,x[M][N],n[N],d[Z];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)cin>>x[i][j];
	}
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n[i];j++)
		{
			for(int k=1;k<=d[i];k++)
			{
				cout<<1;
			}
		}
	}
	return 0;
}