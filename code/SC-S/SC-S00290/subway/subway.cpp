#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long INF=0x3f3f3f3f;
int c,n,dp,m,q,x,y;
vector<int> a[N],t[N],b[N];
int w[N];
int pre[N],idx;
int s,to,k;
long long d[N]; 
bool f[N]; 
long long fun(int s,int si,int fa){
	long long h=INF; 
	for(int i=0;i<b[s].size();i++){
		if(f[b[s][i]]!=true){
			for(int j=0;j<a[b[s][i]].size();j++){
				if(a[b[s][i]][j]==si) return 0;
				if(a[b[s][i]][j]!=fa){
					if(d[a[b[s][i]][j]]==INF){
						fun(a[b[s][i]][j],si,s);
					}
					d[s]=min(d[s],d[a[b[s][i]][j]]+t[s][i]);
					h=min(d[s],h);
				}
			}
		}
	}
	return h;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&dp,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			b[x].push_back(i);
		}
	}for(int i=1;i<=q;i++){
		memset(d,INF,sizeof(d));
		memset(f,false,sizeof(f));
		scanf("%d%d",&s,&to);
		cout<<fun(s,to,0)+w[s]+w[to]<<'\n';
	}
	return 0;
}