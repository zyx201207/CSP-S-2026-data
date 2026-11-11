#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans;
int n,m,mx,mid;
int a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1;
	for(int r=1;r<=n;r++){
		if(a[r]*(r-l+1)-(s[r]-s[l-1])>m){
			while(l<=r&&a[r]*(r-l+1)-(s[r]-s[l-1])>m){
				l++;
			}
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
6 6
1 2 -3 4 5 -6

6 6
-6 -3 -1 2 4 5 
*/
