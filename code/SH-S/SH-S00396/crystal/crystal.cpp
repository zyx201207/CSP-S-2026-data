#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=1,sum=0,beg=1;
	for(int i=2;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]);
		cnt++;
		if(sum>m){
			sum-=a[i]-a[beg];
			cnt--;
			beg++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
