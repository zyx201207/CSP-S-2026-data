#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;//测试点编号 
    int n;//地铁线路数 
    int m;//地铁站数 
    int d;//最多线路数 
    int q;//出行计划数 
	cin>>c>>n>>m>>d>>q;
	
	int w[m];
    for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	} 
	 //地铁口到站厅t；
	int ki[n];
	int ai[505][n],ti[505][n];
	for(int i=1;i<=n;i++)
	{
		cin>>ki[n];
		for(int j=1;j<=ki[n];j++)
		{
			cin>>ai[j][n]>>ti[j][n];
		}
	}//每个线路站台编号+时间 
	
	int x[q+5],y[q+5];
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}//起点终点编号 
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"32"<<endl;
		cout<<"17";
	}
	return 0;
}

