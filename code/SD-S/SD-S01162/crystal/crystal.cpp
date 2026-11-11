#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=501000;
int n;
ll m,a[N],pre[N];
bool check(int l,int r){
	ll sum=pre[r]-pre[l-1];
	return a[r]*(r-l+1)-sum<=m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int r=n,ans=0;
	for(int l=n;l>=1;l--){
		while(!check(l,r))r--;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

