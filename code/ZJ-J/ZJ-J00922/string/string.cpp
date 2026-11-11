#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010];
int sum[200010];
char c[200010];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(sum[l]<=sum[n]/2||sum[r]>=sum[n]/2){
		int cnt=a[l];
		if(a[r]<a[l]){
			if(c[r]!=c[l])ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else if(a[r]==a[l]){
			if(c[r]!=c[l])ans+=a[r];
			l++,r--;
		}
		else{
			if(c[r]!=c[l])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
