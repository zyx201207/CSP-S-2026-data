#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500001];
long long pre[500001];
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int l=1,r=2;l<=n,r<=n;){
		if(a[r]*(r-l)-(pre[r-1]-pre[l-1])<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
