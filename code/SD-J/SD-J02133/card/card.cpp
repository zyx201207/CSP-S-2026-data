#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];//a[n]为每张牌的点数 ，b[m]为出现 次数的桶 
int f(int x,int y)
{
	int u[n],w[m]={},r=0;
	for(int i=0;i<m;i++)
	{
		if(w[a[i]]==0)
		{
			u[r]=a[i];
			r++;
		}
		else
		{
			
			for(int i=0;i<=r;i++)
			
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		
	}
	return 0;
}

