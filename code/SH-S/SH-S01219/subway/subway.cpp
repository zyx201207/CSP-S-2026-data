#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=500009;
const ll N=509;
ll w[N][N],num,t,b,c,n,m,s[M],d,q,cnt,ecnt,o,r,ans;
vector<ll> sta[N],tim[N];
vector<ll> tran[N],T[N];
vector<ll> ha[M],yp[M];
void dfs(int x,int fa,int tp){
	for (int i=0;i<tran[x].size();i++){
		if (w[tp][x]+T[x][i]<w[tp][tran[x][i]]){
			w[tp][tran[x][i]]=w[tran[x][i]][tp]=w[tp][x]+T[x][i];
			dfs(tran[x][i],x,tp);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>s[i];
	for (int g=1;g<=n;g++){
		cin>>b;
		for (int i=1;i<=b;i++){
			cin>>num>>t;
			sta[g].push_back(num);
			tim[g].push_back(t);
			ha[num].push_back(g);
			yp[num].push_back(t);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) w[i][j]=1e10+9;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			cnt=1e10+9;
			for (int k=0;k<sta[i].size();k++){
				for (int l=0;l<sta[j].size();l++){
					if (sta[i][k]==sta[j][l]){ 
						cnt=min(cnt,tim[i][k]+tim[j][l]);
					}
				}
			}
			if (cnt<5*1e9){
				tran[i].push_back(j);
				tran[j].push_back(i);
				T[i].push_back(cnt);
				T[j].push_back(cnt);	
			}
		}
	}
	for (int i=1;i<=n;i++) w[i][i]=0;
	for (int i=1;i<=n;i++) dfs(i,0,i);
	for (int i=1;i<=q;i++){
		cin>>o>>r;
		ans=1e10+9;
		for (int j=0;j<ha[o].size();j++){
			for (int k=0;k<ha[r].size();k++){
				ans=min(ans,w[ha[o][j]][ha[r][k]]+yp[o][j]+yp[r][k]);
			}
		}
		cout<<ans+s[o]+s[r]<<endl;
	}
	return 0;
}
