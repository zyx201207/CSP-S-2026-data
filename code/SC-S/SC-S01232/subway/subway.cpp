#include<bits/stdc++.h>
using namespace std;
struct edge{
	int net,to;
	long long w;
}nod[10000007];
int c,n,m,d,q;
long long mp[505][505];
int head[500005],tot=0;
long long w[500005];
void add_edge1(int x,int y,int t){
	tot++;
	nod[tot].to=y;
	nod[tot].net=head[x];
	nod[tot].w=t;
	head[x]=tot;
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;i++){
		mp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	int a,b; 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
			add_edge1(a,i,b);			
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<"\n";
//		for(int j=head[i];j;j=nod[j].net){
//			cout<<nod[j].to<<" "<<nod[j].w<<" : ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=nod[j].net){
			for(int k=head[i];k;k=nod[k].net){
				if(j==k){
					continue;
				}
				mp[nod[j].to][nod[k].to]=min(mp[nod[j].to][nod[k].to],nod[j].w+nod[k].w);
				mp[nod[k].to][nod[j].to]=mp[nod[j].to][nod[k].to];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]); 
			}
		}
	}
//	for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<mp[i][j]<<" "; 
//			}
//		cout<<"\n";
//		}
	int x,y;
//	cout<<6666;
//	cout<<0x3f3f3f3f3f3f3f3f;
	for(int k=1;k<=q;k++){
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=head[x];i;i=nod[i].net){
			for(int j=head[y];j;j=nod[j].net){
				ans=min(ans,w[x]+w[y]+mp[nod[i].to][nod[j].to]+nod[i].w+nod[j].w);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}