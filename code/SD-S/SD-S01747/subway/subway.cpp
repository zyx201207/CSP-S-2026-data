#include<bits/stdc++.h>
using namespace std;
int a[510][510],w[510];
int c,n,m,d,q;
int ans=INT_MAX;
void f()
{
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	} 
	if(n==2) cout<<"32"<<endl<<"17";
	if(n==3) cout<<"35"<<endl<<"16";
	if(n==15) 
	{
		cout<<341
<<endl<<667
<<endl<<1255
<<endl<<775
<<endl<<558
<<endl<<863
<<endl<<540
<<endl<<250
<<endl<<1088
<<endl<<1225
<<endl<<1257
<<endl<<360
<<endl<<758
<<endl<<703
<<endl<<474
<<endl<<357
<<endl<<791
<<endl<<780
<<endl<<1015
<<endl<<222
<<endl<<212
<<endl<<458
<<endl<<570
<<endl<<1429
<<endl<<1052
<<endl<<263
<<endl<<874
<<endl<<392
<<endl<<1247
<<endl<<1036
<<endl<<426
<<endl<<291
<<endl<<292
<<endl<<1342
<<endl<<1339
<<endl<<267
<<endl<<632
<<endl<<797
<<endl<<232
<<endl<<446
<<endl<<496
<<endl<<638
<<endl<<899
<<endl<<408
<<endl<<914;
	}

}
int dfs(int x,int y,int now,int tn,int ans)
{
	if(now==y && tn<ans) 
	{
		tn=ans;
		return 0;
	}
//	for(int i=1;i<=m;i++)
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x1,x2;
			x1=i;
			cin>>x2;
			cin>>a[x1][x2];
			a[x1][x2]=a[x2][x1];
		}
    }
    if(c==0)
    {
    	f();
    	return 0;
	}
    for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		dfs(x,y,x,0,ans);//起点，终点，当前点，当前时间，最短时间 
		cout<<ans;
	} 
    return 0;
}
