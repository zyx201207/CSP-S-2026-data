#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int sumq[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	int l=1,r=1,sum=0;
	while(l<=r&&r<=n){
		if(sum>m){
			sum-=a[r]-a[l];
			l++;
		}else{
			sum+=(r-l+1)*(a[r+1]-a[r]);
			ans=max(ans,r-l+1);
			r++;
		}
	}cout<<ans;
	return 0;
}

