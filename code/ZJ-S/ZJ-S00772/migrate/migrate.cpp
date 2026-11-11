#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=1e6+7;

int C,T,n,d,a[N],dp[5007][5007];
vector<int>ro1[N],ro2[N];

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<0<<'\n';
			continue;
		} 
		int D=n;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]>d){
				D=i-1;
				break;
			}
		}
		D--;
		for(int i=1;i<=n-D;i++){
			int l=i+D+1,r=min(n,i+2*D-1);
			if(l>n)continue;
			ans+=r-l+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
