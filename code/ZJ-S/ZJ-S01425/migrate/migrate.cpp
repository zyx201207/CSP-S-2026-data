#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll C,T,n,d;
ll a[N],c[N],sum[N];
bool check(ll x,ll y){
	int maxn=0,cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sum[j]-sum[i]<=d){
				if(sum[j]-sum[i]>maxn)maxn=sum[j]-sum[i],cnt=1;
				else if(sum[j]-sum[i]==maxn)cnt++;
			}
		}
	}
	if(cnt==2)return 1;
	else return 0;
}
void solve(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)c[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(check(i,j))ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>C>>T;
	while(T--)solve();
	return 0;
}