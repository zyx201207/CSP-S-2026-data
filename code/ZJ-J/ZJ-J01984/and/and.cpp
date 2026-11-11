#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m;
ll a[1000010],sum,ans=-1;
void dfs(ll wz,ll cnt,ll sum){
	if(cnt == m){
		ans = max(ans,sum);
		return ;
	}
	if(cnt < m && wz > n){
		return ;
	}
	for(ll i=wz+1;i<=n;i++){
		dfs(i,cnt+1,(sum&a[i]));
	}
	return ;
}
bool cmp(ll u,ll v){
	return u>v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(n <= 20){
		sort(a+1,a+n+1,cmp);
		for(ll i=1;i<=n;i++){
			cin >> a[i];
		}
		for(ll i=1;i<=n;i++){
			dfs(i,1,a[i]);
		}
		cout<<ans<<endl;
	}
	else{
		for(ll i=1;i<=n;i++){
			cin >> a[i];
		}
		sort(a+1,a+n+1,cmp);
		if(m==1){
			cout<<a[1]<<endl;
		}
		else if(m==2){
			for(ll i=1;i<=n;i++){
				dfs(i,1,a[i]);
			}
			cout<<ans<<endl;
		}
		else if(m==n){
			ans=a[1];
			for(ll i=2;i<=n;i++){
				ans = (ans&a[i]);
			}
			cout<<ans<<endl;
		}
		else if(a[1]<=3){
			ll cnt[5];
			memset(cnt,0,sizeof cnt);
			for(ll i=1;i<=n;i++){
				cnt[a[i]]++;
			}
			if(cnt[3]>=m){
				cout<<3<<endl;
			}
			else if(cnt[3]+cnt[2]>=m){
				cout<<2<<endl;
			}
			else if(cnt[3]+cnt[1]>=m){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else if(m == n-1){
			ll cnt;
			for(ll i=1;i<=n;i++){
				if(i == 1) cnt=a[2];
				else cnt=a[1];
				for(ll j=1;j<=n;j++){
					if(j == i){
						continue;
					}
					cnt=(cnt&a[j]);
				}
				ans=max(ans,cnt);
			}
			cout<<cnt<<endl;
		}
		else{
			cout<<a[m]<<endl;
		}
	}
	return 0;
}
