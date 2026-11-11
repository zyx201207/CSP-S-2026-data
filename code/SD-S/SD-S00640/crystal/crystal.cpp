#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=0,ans=1,l=n,num=0,u=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	for(int i=n-1;i>=1;i--){
		num=max(ans,num);
		sum+=b[i+1];
		u+=sum;
		ans++;
		if(u>m){
			ans--;
			sum-=b[l];
			u-=b[l]*(l-i);
			l--;
		}
	}
	cout<<max(num,ans);
	return 0;
}

