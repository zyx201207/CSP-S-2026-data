#include<bits/stdc++.h>
using namespace std;
using LL=long long;
//#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
const int N=5e5+10;
LL n,m,a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	LL sum=0;
	int ans=1;
	for(int l=1,r=1;r<=n;r++){
		sum+=a[r];
		int len=r-l+1;
		while(len*a[r]-sum>m){
			sum-=a[l++];
			--len;
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
