#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c,t,n,d,x[N],ans;
struct edge{
	int dis,cnt;
}e[N][N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=n;j++){
			e[i][j]={0x3f3f3f3f3f3f3f3f,0};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				e[i][j]={1,1};
			}
			else{
				break;
			}
		}
	}
	for(int len=3;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			for(int k=i+1;k<j;k++){
				if(e[i][k].dis+e[k][j].dis<e[i][j].dis){
					e[i][j].dis=e[i][k].dis+e[k][j].dis;
					e[i][j].cnt=e[i][k].cnt*e[k][j].cnt;
				}
				else if(e[i][k].dis+e[k][j].dis==e[i][j].dis){
					e[i][j].cnt+=e[i][k].cnt*e[k][j].cnt;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<e[i][j].dis<<" "<<e[i][j].cnt<<"\n";
			if(e[i][j].cnt==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	ans=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}