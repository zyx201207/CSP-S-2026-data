#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q; 
int w[500005];
struct p{
	int ed[10200],edp,le[10200],lep;
}a[20200];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int e,t;
			scanf("%d%d",&e,&t);
			a[e].ed[++a[e].edp]=k+m;
			a[e].le[++a[e].lep]=t;
			a[k+m].ed[++a[k+m].edp]=e;
			a[k+m].le[++a[k+m].lep]=t;
			
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,l=0;
		scanf("%d%d",&x,&y);
		int c[600006],v=1;
		//priority_queue<int,int> len;
		int len[600006];
		for(int i=1;i<=600000;i++){
			len[i]=1<<30;
		}
		c[1]=x;
		len[x]=0;
		while(1){
			bool ok=1;
			for(int j=1;j<=a[v].edp;j++){
				
				int u=len[a[v].ed[j]]; 
				len[a[v].ed[j]]=max(len[a[v].ed[j]],len[c[v]]+a[v].le[j]);
				if(u!=len[a[v].ed[j]]){
					ok=0;
				}
			}
			int id,min=1<<30;
			for(int i=1;i<=n+m;i++){
				if(len[i]<min){
					min=len[i];
					id=i;
				}
			}
			c[++v]=id;
			if(ok==1||c[v]==y){
				l=len[y];
				break;
			}
		}
		printf("%d\n",l+w[x]+w[y]);
	}
	return 0;
}

