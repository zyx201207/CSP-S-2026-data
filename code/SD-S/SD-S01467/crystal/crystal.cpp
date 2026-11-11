#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m,a[N],c[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[n]-a[i];
		s[i]=s[i-1]+c[i];
	}int l=1,r=1;
	while(l<=r&&r<=n){
		int t=s[r]-s[l-1]-c[r]*(r-l+1);
		if(t<=m){
			ans=max(r-l+1,ans);
			r++;
		}else{
			l++;
		}
	}cout<<ans;
	return 0;
}
