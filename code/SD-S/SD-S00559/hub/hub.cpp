//long long
//清空文件夹其他文件
//freopen!!!文件名+别注释 
//线段树开4倍，双向边开2倍，不同点组开总点数倍，小心N的+10和循环上界，小心越界，未定义行为!!! 
//别用endl 
//考虑各种特例 
//初始化问题!! 
//多测清空!!!
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

const int N=2e6+10;

int cnum,T;
int n,k;
int head[N];
struct Edge{
	int next,to;
}e[N<<1];

int tote=0;
void add_edge(int from,int to){
	++tote;
	e[tote].next=head[from];
	head[from]=tote;
	e[tote].to=to;
	return ;
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>cnum>>T;
	
	while(T--){
		cin>>n>>k;
		
		tote=0;
		for(int i=0;i<=n;++i){
			head[i]=0;
		}
		
		int u,v;
		for(int i=1;i<n;++i){
			cin>>u>>v;
			add_edge(u,v);
			add_edge(v,u);
		}
		
		if(cnum==13||cnum==14){
			if(k==n){
				cout<<0<<'\n';
				continue;
			}
			int m=(n>>1);
			if(k>=m){
				cout<<1<<'\n';
				continue;
			}
			if(k==1){
				cout<<ceil((m+1)*1.000/2)<<'\n';
				continue;
			}
			int ans=0;
			ans=ceil((m-k+5)*1.00/4);
			cout<<ans<<'\n';
			continue;
		}
		
	} 
	
	return 0;
} 
