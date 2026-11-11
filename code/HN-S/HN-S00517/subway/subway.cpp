//subway
#include<bits/stdc++.h>
int c,n,m,d,p;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[500000];//依次表示从每个地铁站的地铁口走到站厅需要的时间
bool k1[1][1];
int k[1][1],xian[1][1];
using namespace std;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>p; 
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	
	for(int i=0;i<n;i++)
	{
		int l;
		cin>>l;
	for(int j=0;j<l;j++)
		cin>>xian[1][1]>>k[1][1];
		
	}
	int x,y,s;
	cin>>x>>y;
	s+=w[x]+w[y];
	cout<<s+d;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
