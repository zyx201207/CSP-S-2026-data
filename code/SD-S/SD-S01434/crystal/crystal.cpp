#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500010;
ll n,m;
ll a[MAXN];
ll pre[MAXN];
bool isok=true;
ll cnt[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	
	a[0]=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		pre[i]=a[i-1]-a[i];
		if(i=!1&&pre[i-1]!=pre[i]){
			 isok=false;
		}
		sum+=a[i];
	} 
	if(isok){
		ll num=0;
		num=m/pre[n];
		cout<<num<<"\n";
		return 0;
	}else{
		ll mid=1LL*sum/n;
		ll minn=LLONG_MAX;
		for(int i=1;i<=n;i++){
			if(a[i]-mid<0){
				continue;
			}
			minn=min(minn,a[i]-mid);
		} 
		for(int i=1;i<=n;i++){
			cnt[i]=a[i]-minn;
		}
		ll ans=0;
		sort(cnt+1,cnt+1+n);
		for(int i=1;i<=n;i++){
			if(m-cnt[i]>=0){
				ans++;
				m-=cnt[i];
			}
			if(m==0){
				break;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
