#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],sum[N],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		if(a[i]*(i-1-l+1)-sum[i-1]+sum[l-1]<=m){
			ans=max(ans,(i-l+1));
		}
		else{
			for(;l<=i;){
				if(a[i]*(i-1-l+1)-sum[i-1]+sum[l-1]>m)l++;
				else break;
			}
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans;
	return 0;
}
//连雨不知春去，一晴方知夏深