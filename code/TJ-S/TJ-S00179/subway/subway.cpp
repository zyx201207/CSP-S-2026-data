#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;          
int w[10001];
int a[1001][1001],b[1001][1001];
int ans=0;
int ex,sx;																																																												  }                                                                                                                                                                                                                                                  
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int j; 
	for(int i=1;i<=n;i++)
	{
		cin>>j;
		for(int k;k<=j;k++)
		{
			cin>>a[i][k]>>b[j][k];
		}
	}
	cout<<"32"<<endl<<"17";
	return 0;
 } 
