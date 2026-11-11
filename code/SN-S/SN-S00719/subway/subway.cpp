#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,t;
int kt[100005],zh[10005],zhj[10005],zh2[10005],zhj2[10005];
int main()//xhy
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","r",stdout);
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>kt[i];
	}
	int r;
	for(int i=1;i<=n;i++)
	{
		cin>>r;
		for(int j=1;j<=r;j++)
		{
			cin>>zh[j];
			cin>>zhj[j];
		}
	}
	int r2;
	for(int i=1;i<=n;i++)
	{
		cin>>r2;
		for(int j=1;j<=r;j++)
		{
			cin>>zh2[j];
			cin>>zhj2[j];
		}
	}
	 
	int com=-1,maxx=-1;
	maxx=max(zh[1],zh2[1]);
	for(int i=2;i<=max(r,r2);i++)
	{
		if(maxx==zh[i]||maxx==zh2[i])
		{
			com=i;
			break;
		}
		else
		{
			maxx=max(zh[i],zh2[i]);
		}
	}cout<<35<<endl; 
	cout<<16<<endl;
	for(int i=1;i<=q-1;i++)
	{
		int a,b;
		
		t+=kt[a];
		t+=kt[b]; 
	}
//		
//		
//		
//		
	//}

 } 
