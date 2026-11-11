#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll cnt=0,ans=0,sum=0;
	for (int i=n;i>0;i--){
		ans++;
		cnt+=(a[i]-a[i-1])*ans;
		while(cnt>m){
			cnt-=a[ans+i-1]-a[i-1];
			ans--;
		}
		sum=max(ans,sum);
	}
	cout<<sum+1;
	return 0;
}