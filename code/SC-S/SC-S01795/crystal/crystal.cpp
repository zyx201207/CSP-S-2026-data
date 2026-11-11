#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//前缀和，二分顶尖杂交
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,m,ans=LONG_LONG_MIN;
	cin>>n>>m;
	vector<ll> s(n+5),qz(n+5);
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s.begin()+1,s.begin()+n+1);
	qz[0]=0;
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+s[i];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i-1;
		ll mid=(l+r)/2,res=mid;
		while(l<=r){
			mid=(l+r)/2;
			ll sum=s[i]*(i-mid);
			ll p=qz[i-1]-qz[mid-1];
			ll need=sum-p;
			if(m>=need){
				r=mid-1;
				res=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}cout<<ans;
	return 0;
}