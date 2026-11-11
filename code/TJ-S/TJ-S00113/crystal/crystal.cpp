#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll check(ll n){
	if(n%2==0)return n/2*(n+1);
	else return(n+1)/2*n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a,b;
	cin>>a>>b;
	bool temp=1;
	ll x;
	map<ll,ll>mp;
	for(int i=1;i<=a;i++){
		cin>>x;
		if(x!=i)temp=0;
		mp[x]++;
	}
	if(temp){
		ll l=1,r=1000000000,ans=0;
		while(l<=r){
			
			ll mid=(l+r)/2;
			if(check(mid)>=b){
				ans=min(a-1,mid);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		cout<<ans+1;
	}
	else{
		map<ll,ll>add;
		for(int i=-100000;i<=100000;i++){
			if(mp[i]>0){
				int m2=b;
				for(int j=i-1;j>=-100000;j--){
					if(mp[j]>0){
						ll x=floor(m2*1.0/(abs(i-j)));
						if(x>0){
							add[i]+=min(x,mp[j]);
							m2-=min(x,mp[j])*(abs(i-j));
						}
						else{
							break;
						}
					}
				}
			}
		}
		ll maxn=-1;
		for(int i=-100000;i<=100000;i++){
			maxn=max(maxn,mp[i]+add[i]);
		}
		cout<<maxn;
	}
	return 0;
} 
