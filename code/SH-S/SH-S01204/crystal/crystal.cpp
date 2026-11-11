#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],pre[500005],l=1,r=2,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	while(r<=n){
		if((a[r]*(r-l)-pre[r-1]+pre[l-1]<=m)||(l==r)){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
