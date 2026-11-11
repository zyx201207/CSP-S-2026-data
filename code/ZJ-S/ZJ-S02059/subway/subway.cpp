#include<bits/stdc++.h>
#define int long long 
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(int (i)=(b);(i)>=(a);(i)--)
#define ct continue
#define endl '\n'
using namespace std;
const int N=1e6+5,MOD=1e9,INF=1e18;
int t[N];
int t2[N];
vector<int>t_to[N];
int dp[N];
//ci chu sheng lve yue 170 hang de fei an shi shan code
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(n==1){
		For(i,1,m)cin>>t[i];
		int k;cin>>k;
		For(i,1,k){
			int a,b;cin>>a>>b;
			t2[i]=b;
		}
		int st,ed;cin>>st>>ed;
		int ans=0;
		For(i,st,ed)ans+=t2[i];
		cout<<ans+t[st]+t[ed];
	}else{
		For(i,1,m)cin>>t[i];
		int v;
		For(i,1,n){
			int k;cin>>k;
			For(j,1,k){
				int x;cin>>x>>v;
				t_to[x].push_back(i);
			}
			dp[i]=0;
		}
		For(i,1,m){
			if(t_to[i].size()>=2){
				For(k,0,t_to[i].size()-1){
					For(j,k,t_to[i].size()-1){
						int pk=t_to[i][k];
						int pj=t_to[i][j];
						if(k==j) dp[pj]=dp[pk];
						else dp[pj]=max(dp[pk]+1,dp[pj]);
					}
				}
			}
		}
//		For(i,1,n){
//			cout<<dp[i]<<" ";
//		}cout<<endl;
		For(i,1,q){
			int st,ed;cin>>st>>ed;
			int ans=t[st]+t[ed];
			int cnt=INF;
			For(j,0,t_to[ed].size()-1){
				cnt=min(cnt,dp[t_to[ed][j]]);
			}
			cout<<ans+cnt*v<<endl;
		}
	}
	return 0;
}
//ni ying le,ni de ti mu xiao zhong you du te
//wo shu le,wo de xie fa you chou you chang
//spend 1.5h
//c
//n
//m
