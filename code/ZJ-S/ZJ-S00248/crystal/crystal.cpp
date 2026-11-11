#include<bits/stdc++.h>
using namespace std;
__int128 a[500010];
__int128 z[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		a[i]=x;
		z[i]=z[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		z[i]=z[i-1]+a[i];
	}
	int ans=0;
	int l=1,r=1;
	while(l<=n&&r<=n){
		if(a[r]*(r-l+1)-(z[r]-z[l-1])<=m){
			ans=max(r-l+1,ans);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}