#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);i++)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);i--)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);i++)
typedef long long ll;
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'

template<typename T=int>T read(){T x;cin>>x;return x;}
const int N=2e6+5;
ll x[N],g[1005],f[1005][1005];
int C;
int n;
ll d;
void MAIN(){
	cin>>n>>d;
	For(i,1,n) cin>>x[i];
	ll ans=0;
	For(u,1,n){
//		cout<<u<<endl;
		g[u]=0;
		For(i,u+1,n){
			g[i]=n;
		}
		For(i,u+1,n){
			foR(j,i-1,u){
				if(x[i]-x[j]<=d)g[i]=min(g[i],g[j]+1);
				else break;
			}
		}
		For(i,u+1,n)For(j,g[i],n) f[i][j]=0;
		f[u][0]=1;
		For(i,u+1,n){
			For(j,u,i-1){
				if(g[j]+1==g[i]&&x[i]-x[j]<=d){
					f[i][g[i]]+=f[j][g[j]];
//					cout<<i<<" "<<g[i]<<" "<<f[i][g[i]]<<endl;
//					cout<<j<<" "<<g[j]<<" "<<f[j][g[j]]<<endl;
				}
			}
		}
		For(i,u+1,n) ans+=(f[i][g[i]]==2);
	}
	cout<<ans<<endl;
}signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	C=read();int t=read();while(t--){
		MAIN();
	}
	return 0;
}
