#include<bits/stdc++.h>
#define LL long long
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)
using namespace std;
const int N=2e6+5;
const int inf=1e9;
int c,T,n,dp[N],op[N];
LL ans,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		For(i,1,n){
			cin>>a[i];
		}
		ans=0;
		For(i,1,n){
			For(j,i+1,n)	dp[j]=inf,op[j]=0;
			dp[i]=0;op[i]=1;
			For(j,i+1,n){
				For(k,i,j-1){
					if(a[j]-a[k]<=d){
						if(dp[j]>dp[k]+1){
							dp[j]=dp[k]+1;op[j]=op[k];
						}else if(dp[j]==dp[k]+1){
							op[j]+=op[k];
						}
					}
				}
				ans+=(op[j]==2?1:0);
//				cout<<op[j]<<" "<<i<<" "<<j<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}