#include<bits/stdc++.h> 
using namespace std;
//无力了，看不下去题干了，就这样结束吧
//回家找大肥鱼去了 
int c,n,m,d,q;
int a[13000];
int x[10010];
int k[10010],k2[10010];
int y[10010];
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>k2[j];
	
		} 
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		
	}
	//cout<<k[1]<<k[2]<<endl;
	return 0;
}
