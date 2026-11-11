#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k[500010],x,y,v[20010][20010];
struct node{
	int a,t;
}a[1010][1010];
int check(int x,int y){
	for(int i=1;i<=k[y];i++)if(a[y][i].a==x)return i;
}
void dfs(int x,int sum,int &mn){
	if(x==y){
		mn=min(mn,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			bool f=0;
			if(a[i][j].a==x){
				f=1;
				for(int k1=1;k1<=k[i];k1++){
	
					if(v[x][a[i][k1].a]==0&&x!=a[i][k1].a){	
						v[x][a[i][k1].a]=1;
						sum+=a[i][k1].t;
						sum+=a[i][check(x,i)].t;
						
						dfs(a[i][k1].a,sum,mn);
						
						v[x][a[i][k1].a]=0;
						sum-=a[i][k1].t;
						sum-=a[i][x].t;	
					}
				}	
			}
			if(f==1)break;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].a>>a[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		memset(v,0,sizeof(v));
		cin>>x>>y;
		int mn=1e9;
		dfs(x,w[x]+w[y],mn);
		cout<<mn<<endl;
	}
	
	return 0;
}
