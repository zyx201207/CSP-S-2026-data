#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[500005],mn=1000000000000,mx=-1000000000000,ans=1;
ll chk(ll x){
	ll s=0,p=m,cnt=0;
	for(int i=n;i>0;i--){
		if(a[i]>x)continue;
		if(p<(x-a[i]))break;
		s+=(x-a[i]);
		p-=(x-a[i]);
		cnt++;
	}return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=false;
	cin>>n>>m>>a[1]>>a[2];
	ll k=a[2]-a[1];
	mx=max(mx,max(a[1],a[2]));
	mn=min(mn,min(a[1],a[2]));
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=k)f=true; 
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}if(f==false){
		ll cnt=0;
		for(int i=k;;i+=k){
			if(m<i)break;
			cnt++;
			m-=i;
		}cout<<cnt+1;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=mn;i<=(mx+m/n);i++)ans=max(ans,chk(i));
	cout<<ans;
} 
