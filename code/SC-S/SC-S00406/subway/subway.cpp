#include<bits/stdc++.h>
using namespace std;
struct ed{
	int n,l;
};
int c,n,m,d,q,k,x,y,dist[1000001],a[1000001],t[1000001],ro[1000001];
vector<ed> g[1000001];
void find(int x){
	for(int j=0;j<g[x].size();j++){
		dist[g[x][j].n]=min(g[x][j].l,dist[g[x][j].n]);
		find(g[x][j].n);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>ro[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(a[j]==a[l])continue;
				ed tmp;
				tmp.n=a[l],tmp.l=t[l]+t[j];
				cout<<a[j]<<" "<<tmp.n<<" "<<tmp.l<<endl;
				g[a[j]].push_back(tmp);
			}
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		memset(dist,0x3f3f3f,sizeof(dist));
		find(x);
		cout<<dist[y]+ro[x]+ro[y]<<endl;
	}
	return 0;
}