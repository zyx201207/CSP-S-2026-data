#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+50;
int c,n,m,d,q;
int ww[MAXN],w[20000][20000];
int ans,jis;
struct A{
	int u,v,t;
	bool operator <(const A b){
		return t<b.t;
	}
}a[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	
	if((c>=1&&c<=3)||c==20||c==21){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int kkk;
			for(int j=1;j<=k;j++){
				int v,t;
				cin>>v>>t;
				w[i][v]=t;
			}
		}
		while(q--){
			ans=0;
			int x,y;
			cin>>x>>y;
			ans+=ww[x]+ww[y];
			if(w[1][x]!=0&&w[1][y]!=0){
				ans+=w[1][x]+w[1][y];
			}else if(w[2][x]!=0&&w[2][y]!=0){
				ans+=w[2][x]+w[2][y];
			}else{
				ans+=max(w[1][x],w[2][x])+max(w[1][y],w[2][y]);
				int lins=0x3f3f3f3f;
				for(int i=1;i<=m;i++){
					if(w[1][i]!=0&&w[2][i]!=0){
						ans+=w[1][i]+w[2][i];
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			int ooo,t,v,t1,v1;
			cin>>ooo>>t>>v>>t1>>v1;
			w[t][t1]=v+v1;
			a[++jis].u=t;
			a[jis].v=v;
			a[jis].t=v+v1;
		}
		sort(a+1,a+1+jis);
		while(q--){
			ans=0;
			int x,y;
			cin>>x>>y;
			ans+=ww[x]+ww[y];
		}
	}
}