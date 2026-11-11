#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2 and a[i]-a[i-1]!=a[2]-a[1])
			flag=false;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>ans;i--){
		int sum=0,cnt=0;
		for(int j=i;j>=1;j--){
			if(sum+(a[i]-a[j])<=m)
				sum+=(a[i]-a[j]),cnt++;
			else break;
		}
		ans=max(ans,cnt);
		if(flag)break;
	}
	cout<<ans;
	return 0;
}
