#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],sum[maxn],flag=0,flag1=0,pos,ans1=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) flag++;
	} 
	int cnt=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==cnt) flag1++;
	} 
	if(flag1==n-1||flag==n-1){
		sort(a+1,a+n+1);
		sum[1]=a[2]-a[1];
		for(int i=2;i<n;i++) sum[i]=sum[i-1]+i*(a[i+1]-a[i]);
		int ans=upper_bound(sum+1,sum+n,m)-sum;
		cout<<ans<<endl;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				pos+=(a[i]-a[j]);
				if(pos>m){
					ans1=max(ans1,i-j);
					break;
				} 
			}
			if(pos<=m) ans1=max(ans1,i);
			pos=0;
		}
		cout<<ans1<<endl;
	}
	return 0;
}