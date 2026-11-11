#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
int n;
ll m;
ll a[N];
ll pre[N];
ll get(int l,int r){
	return pre[r]-pre[l-1];
}
int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		while(1ll*a[i]*(i-l+1)-get(l,i)>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}