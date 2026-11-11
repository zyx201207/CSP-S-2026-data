#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],L,R,r,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int l=1;l<=n;l++){
		L=0;
		R=n;
		while(L+1<R){
			r=L+R>>1;
			if(a[r]*(r-l+1)-(s[r]-s[l-1])>m){
				R=r;
			}
			else{
				L=r;
			}
		}
		ans=max(ans,L-l+1);
	}
	cout<<ans;
	return 0;
}
/*
67 83 80 82 80 43 61 73 78 70 70 33
*/
