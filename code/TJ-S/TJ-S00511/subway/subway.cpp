#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
long long wt[50005];
long long g[505][5005];
int i;
int j;
int fa[50005]={};
struct road{
	long long num,di,t;
}e[505][50005];
void init(){
	for(int i=1;i<=m;i++) fa[i]=i;
}
void merge(int p,int q){
	int pp=fa[p];
	int qq=fa[q];
	if(pp==qq) return ;
	for(int i=1;i<=m;i++){
		if(fa[i]==qq){
			fa[i]==pp;
		}
	}
}
void gou(){
	
	for(i=1;i<=n;i++){
		for(j=1;j<=e[i][j].num;j++){
			for(int k=1;k<=m;k++){
				g[e[i][j].di][k]=max(g[e[i][j].di][k],e[i][j].t);
				g[k][e[i][j].di]=max(g[e[i][j].di][k],e[i][j].t);
				
			}
			merge(e[i][1],e[i][j].di);
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			g[i][j]+=wt[i]+wt[j];
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++){
		cin>>wt[i];
	}
	for(i=1;i<=n;i++){
		int num;
		cin>>num;
		
		for(j=1;j<=num;j++){
			e[i][j].num=num;
			cin>>e[i][j].di>>e[i][j].t; 
		}
	}	
	
	gou();
	for(i=1;i<=q;i++){
		int st,fi;
		cin>>st>>fi;
		cout<<g[st][fi]<<endl;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
