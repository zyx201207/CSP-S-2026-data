#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int N=5e5+9;
ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1ll;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
ll n,m,ans;
ll a[N],s[N];
bool check(ll x,ll i){
	ll sum=s[i-1]-s[x-1]+a[i]*(i-x);
//	cout<<s[i-1]<<' '<<s[x-1]<<' '<<a[i]*(i-x)<<endl;
//	cout<<"x:"<<x<<' '<<"i:"<<i<<' '<<"sum:"<<sum<<endl;
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]-a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,t;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				t=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
//		cout<<t<<' ';
		
		ll len=i-t+1;
		ans=max(ans,len);
//		cout<<ans<<endl;
	}
//	cout<<endl;
	cout<<ans<<endl;
//	for(int i=1;i<=n;i++) cout<<s[i]<<' ';
	return 0;
} 
/*
5 5
1 2 4 8 9

*/
