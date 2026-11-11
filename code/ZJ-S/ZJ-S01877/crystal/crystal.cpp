#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],s,t,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll tt=s+t*(a[i]-a[i-1]);
		if(tt<=m){
			s=tt;
			t++;
			ans=max(ans,t);
		}
		else if(t>0){
			while(tt>m&&t>0){
				s=s-(a[i-1]-a[i-t]);
				t--;
				tt=s+t*(a[i]-a[i-1]);
			}
			if(tt<=m){
				s=tt;
				t++;
				ans=max(ans,t);
			}
		}
	}
	cout<<ans;
	return 0;
}
