#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll l=0,r;
ll check(int x){
	ll sum=0;
	int temp=m;
	for(int i=n;i>=1;i--){
		if(temp==0) break;
		if(a[i]>x) continue;
		else{
			if(x-a[i]>temp){
				break;
			}
			sum++;
			temp-=x-a[i];
		}
	}
	return sum;
}
bool cmp(int x,int y){
	return x<y; 
}
int main(){//¶ş·Ö£¿ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flag=true;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=0;
		r=max(r,a[i]);
		l=min(l,a[i]);
	}
	ll ans=0;
	sort(a+1,a+1+n,cmp);
	
	if(flag){
		ll x=0;
		ll minu=0;
		ll cur=0;
		while(minu*2>=m){
			m-=minu;
			x+=cur;
			if(cur==0) cur++;
			else cur*=2;
			if(minu==0) minu++;
			else minu*=2;
		}
		while(m>l){
			m-=minu;
			x++;
			minu++;
		}
		if(m<l) x--; 
		cout<<x;
		return 0;
	}
	while(l<r){
		int mid=(l+r)/2;
		int res=check(mid);
		if(res>ans){                                
			ans=res;
			l=mid+1; 
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
