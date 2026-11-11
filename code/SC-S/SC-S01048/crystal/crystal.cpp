#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
int n;
ll m;
int ans;
ll a[N];
void cheak(ll sum){
	ll cnt1=0;
	ll cnt2=0;
	int x1;
	for(int i=1;i<=n;i++){
		ll b;
		if(a[i]<=sum){
			b=sum-a[i];
			x1=i;
			cnt1+=b;
		}
		else{
			b=a[i]-sum;
			cnt2+=b;
		}
	}
	int x2=n-x1;
	if(cnt1<=m&&cnt2>m)ans=max(ans,x1);
	if(cnt1>m&&cnt2<=m)ans=max(ans,x2);
	if(cnt1<=m&&cnt2<=m){
		int x=max(x1,x2);
		ans=max(ans,x);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cheak((a[n]+a[1])>>1);
	int cnt=ans;
	cheak(a[n]>>1);
	ans=max(cnt,ans);
	cout<<ans;
	return 0;
}