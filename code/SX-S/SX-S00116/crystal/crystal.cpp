#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505000;
ll n,m,a[N],ch,ans=0;
bool f=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	ch=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=ch) f=0;
	}
	if(f==1){
		for(int i=n;i>=1;i--){
			if(m-(a[n]-a[i])>=0) m-=(a[n]-a[i]),ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	ll sum=0;
	for(int i=1;i<=n;i++){
		ans=0;
		ll m1=m;
		for(int j=i;j>=1;j--){
			if(m1-(a[i]-a[j])>=0) m1-=(a[i]-a[j]),ans++;
			else break;
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}
