#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=500002;
constexpr int L=505;
constexpr int D=20;
constexpr ll F=90000020261031;
int c,n,m,d,q,nxt[N];
struct nd{int v,t;}trans[N][D];
ll sp[L][L],ex[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=0;i<L;i++) for(int j=0;j<L;j++) if(i!=j) sp[i][j]=F;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ex[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			trans[a][nxt[a]++]={i,t};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<nxt[i];j++){
			for(int k=0;k<j;k++){
				int x=trans[i][j].v,y=trans[i][k].v;
				sp[x][y]=sp[y][x]=min(sp[x][y],(ll)(trans[i][j].t+trans[i][k].t));
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
	while(q--){
		int x,y,td;ll ans=F,tmp;
		cin>>x>>y;
		for(int i=0;i<nxt[x];i++){
			for(int j=0;j<nxt[y];j++){
				tmp=ans;
				ans=min(ans,sp[trans[x][i].v][trans[y][j].v]+ex[x]+ex[y]);
				if(ans<tmp) td=trans[x][i].t+trans[y][j].t;
			}
		}
		ans+=td;
		cout<<ans<<"\n";
	}
	return 0;
}
