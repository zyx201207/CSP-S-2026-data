#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],b[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0;
	int sum=0,cnt=1;
	while(r<=n){
		ans=max(ans,r-l+1);
		r++;
		sum+=(a[r]-a[r-1])*cnt;
		cnt++;
		while(sum>m&l<=r){
			cnt--;
			sum-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}