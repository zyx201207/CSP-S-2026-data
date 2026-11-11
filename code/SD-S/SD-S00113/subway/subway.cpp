#include<bits/stdc++.h>
using namespace std;
struct nod{
	int x,nex,w;
}tr[4000005];
struct no{
	int ne,w;
}arr[500005];
int w[500005];
int mi[1005][1005],pos,hea[500005];
bool fl[1005];
struct node{
	int x,w;
	bool operator<(const node &oth)const{
		return w>oth.w;
	}
};
priority_queue<node> qu;
int bfs(int x,int z){
	node a;
	a.x=x,a.w=0;
	qu.push(a);
	while(qu.size()>0){
		node b=qu.top();
		qu.pop();
		if(fl[b.x]==1)
			continue;
		int y=hea[b.x];
		fl[b.x]=1;
		if(b.x==z)
			return b.w;
		for(;y;y=tr[y].nex){
			if(fl[tr[y].x]==0){
				node c;
				c.x=tr[y].x;
				c.w=b.w+tr[y].w;
				qu.push(c);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&arr[j].ne,&arr[j].w);
		}
		for(int j=1;j<k;j++){
			for(int t=j+1;t<=k;t++){
				int c=arr[j].w+arr[t].w;
				int a=min(arr[j].ne,arr[t].ne),b=max(arr[j].ne,arr[t].ne);
				if(mi[a][b]==0)
					mi[a][b]=c;
				else
					mi[a][b]=min(mi[a][b],c);
			}
		}
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(mi[i][j]>0){
//				cout<<i<<" "<<j<<" "<<mi[i][j]<<endl;
				tr[++pos].nex=hea[i];
				tr[pos].x=j;
				tr[pos].w=mi[i][j];
				hea[i]=pos;
				tr[++pos].nex=hea[j];
				tr[pos].x=i;
				tr[pos].w=mi[i][j];
				hea[j]=pos;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=m;i++){
			fl[i]=0;
		}
		int ans=bfs(a,b);
		ans+=w[a]+w[b];
		printf("%d\n",ans);
	}
	return 0;
}
