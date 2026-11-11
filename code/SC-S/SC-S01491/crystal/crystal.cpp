#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,ans=1;
ll m,a[N],pre[N];
ll sum(int l,int r){
	return pre[r]-pre[l-1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
		if(i==1) continue;
		while(i-ans>=1&&ans<i
		&&1LL*(ans+1)*a[i]-sum(i-ans,i)<=m){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
