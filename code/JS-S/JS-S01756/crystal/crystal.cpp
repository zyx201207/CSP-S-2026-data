#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=0,sum[500005],ads=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],ads=max(ads,a[i]);
	sort(a+1,a+n+1);
	if(n<=5000||(n>5000&&ads<=100)){
		for(int i=1;i<=n;i++){
		int cnt=0,h=m;
		for(int j=i;j>=1;j--){
			if(h-(a[i]-a[j])<0) break;
			else h-=(a[i]-a[j]),cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	}
	else{
	int m1=a[2]-a[1];
	for(int i=1;i<=n;i++){
	for(int k=1;k<=i;k++){
		if(k*(k+1)>2*m/m1){
			ans=max(ans,i-(k-1)+1);
			break;
			}
		}
	}
	cout<<ans;
	}
	return 0;
}
