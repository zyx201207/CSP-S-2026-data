#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],cur,l,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	for (int i = 1; i <= n; i++){
		cur+=(a[i]-a[i-1])*(i-l);
		while (cur>m){
			cur-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
/*
Ç©µ½ÌâT1 
*/
