#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int c,t;
int n;
ll d;
ll x[N];
pair<int,ll>dp[N];//v cnt
ll pre[N];
ll ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10 || c>12){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i]; 
			}
			for(int i=1;i<=n;i++){
				int l=i,r=i;
				for(int j=i-1;j<=n;j++){
					dp[j]={0,0};
					pre[j]=0;
				}
				dp[i]={0,1};
				pre[i]=1;
				for(int j=i+1;j<=n;j++){
					while(l<j && x[j]-x[l]>d){
						l++;
						while(r<j-1 && dp[r+1].first<=dp[l].first){
							r++;
						}
					}
					if(l==j){
						break;
					}
					dp[j]={dp[l].first+1,pre[r]-pre[l-1]};
					if(dp[j].second==2){
						ans++;
					}
//					cout<<i<<' '<<j<<' '<<dp[j].first<<' '<<dp[j].second<<" l="<<l<<" r="<<r<<endl;
					pre[j]=pre[j-1]+dp[j].second;
				}
			}
			cout<<ans<<endl;
		}
	}else if(c>=11 && c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			d/=x[2]-x[1];
			if(d<=1){
				cout<<0<<endl;
			}else{
				cout<<max(0ll,n-2*d+1)<<endl; 
			}
		}
	}
	return 0;
}
