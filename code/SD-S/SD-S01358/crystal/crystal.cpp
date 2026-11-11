#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const ll N=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
ll n,m,a[N],c[N],b[N],s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	s=unique(b+1,b+n+1)-b-1;
	ll no=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			no++;
			c[no]++;
		}else c[no]++;
	}
	ll ans=0;
	for(int i=1;i<=s;i++){
		ll si=0,sum=0;
		for(int j=i;j>=1;j--){
			if(sum+(b[i]-b[j])*c[j]<=m){
				si+=c[j];
				sum+=(b[i]-b[j])*c[j];
			}else{
				si+=(m-sum)/(b[i]-b[j]);
				sum+=(m-sum)/(b[i]-b[j])*(b[i]-b[j]);
				break;
			}
		}
		ans=max(ans,si);
	}
	cout<<ans;
	
	return 0;
}
//Oct31==Dec25?
//crystal subway migrate hub
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const ll N=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
ll n,m,a[N],c[N];
ll fd(ll x,ll k){
//	cout<<x<<endl;
	if(x*k+m>=c[1]) return 0;
	ll l=0,r=k,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
	//	cout<<l<<" "<<r<<" "<<c[mid]-x*(k-mid+1)<<"#";
		if(c[mid]-x*(k-mid+1)>m){
			l=mid+1;
		}else{
			ans=mid;
			r=mid-1;
		}
	//	cout<<" "<<ans<<"*"<<endl;
	}
	return ans;
}
int main(){
	freopen("using.in","r",stdin);
	freopen("using.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		c[i]=c[i+1]+(a[n]-a[i]);
	}
	c[0]=INF;
//	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
//	cout<<endl;
	ll ans=0;
	for(int i=n;i>=1;i--){
//		cout<<i<<":";
	//	cout<<fd(c[i],i)<<"\n%%%%%%%%%%%%%%%%%%%%"<<endl;
		ans=max(ans,i-fd(c[i],i)+1);

	}
	cout<<ans;

	return 0;
}
*/
