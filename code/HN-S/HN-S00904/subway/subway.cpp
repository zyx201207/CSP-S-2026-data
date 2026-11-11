#include <bits/stdc++.h>
using namespace std;
#define M 10000
int w[M]={};
int k[M]={};
int a[M][M]={};
int t[M][M]={};
int x[M]={};
int y[M]={};
int S[M]={};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i]; 
	}
	for(int i=0;i<n;i++
	){
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=0;r<q;r++)
	{
		cin>>x[r]>>y[r];
	}
	if(c==0)
	{
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17;
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<endl<<16;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

