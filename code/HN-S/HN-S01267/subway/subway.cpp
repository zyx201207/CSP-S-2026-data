#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long w[10001]={};
struct sub{
	long long zhan[10001];
	long long t[10001];
	long long huancheng[10001][30];
	long long dangqian[10001];
}a[105];//Ã¿tiaoditieÇé¿ö 
long long visit[100001]={};
long long thans[10000]={};
int minlu=1000000;
long long shuju[10001]={};
long long x,y;
void dfs(int lu,long long dqz,long long dqdt){
	if(dqz==y){
		lu+=a[dqdt][y].t;
		minlu=min(minlu,lu);
		return ;
	}
	for(int i=1;i<=a[dqdt].dangqian[dqz];i++){
		for(int j=1;a[i].zhan[j]!=0;j++){
			if(a[i].dangqian[j])
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;i++){
			cin>>a[i].zhan[j]>>a[i].t[j];
			a[i].huancheng[a[i].zhan[j]][++a[i].dangqian[j]]=i; 
		}
	}
	for(int i=1;i<=q;i++){
		minlu=1000000;
		cin>>x>>y;
		visit[x]=true;
		dfs(0,x,0);
		visit[x]=false;
		shuju[i]=minlu+w[x]+w[y];
	}
	for(int i=1;i<=q;i++){
		cout<<shuju[i]<<'\n';
	}
} 
