#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=5005; 
ll d;
int n;
ll x[N];
bool op[N];
int dp[N];
int cnt[N];
ll dis(int a,int b){

	if(op[a]&&op[b]){
		return x[a]-x[b];
	}else if(op[a]&&!op[b]){
		return x[b]+x[a];
	}else{
		return x[b]-x[a];
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		x[i]=0;
		op[i]=0;
	}
	string s;
	for(int i=1;i<=n;++i){
		cin>>s;
		int m=s.size();
		if(s[0]=='-'){
			
			op[i]=false;
			for(int j=1;j<m;j++){
				x[i]=x[i]*10+(s[j]-'0');
			}
		}else{
			op[i]=true;
			for(int j=0;j<m;j++){
				x[i]=x[i]*10+(s[j]-'0');
			}
		}
	}

	ll ans=0;
	for(int u=1;u<=n;++u){
		for(int i=1;i<=n;++i){
			dp[i]=INT_MAX;
			cnt[i]=0;
		}
		for(int i=u;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(dis(j,i)<=d){
					if(dp[j]==dp[i]+1){
						cnt[j]++;
					}else if(dp[i]+1<dp[j]){
						cnt[j]=1;
						dp[j]=dp[i]+1;
					}
				}
			}
		}
		for(int v=u+1;v<=n;++v){
			if(cnt[v]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
