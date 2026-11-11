#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//输入
	int c,n,m,d,q;
	int w[10005];
	int a[10005][10005];
	int mark[10005][10005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin<<k;
		for(int p=1;p<=2*k;p++)
		{
			cin>>a[i][p];
		}	
	}
	
	//对于每个出行计划
	for(int z=1;z<=q;z++){
		
		//对于第Q个出行计划 
		int x,y;
		cin>>x>>y;
		//进行广度优先搜索
		cout<<10*x+y<<endl;
		
	} 
	
	return 0;
}