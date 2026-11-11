#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int h=0,ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=(i-h-1)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[++h];
		}
		ans=max(ans,i-h);
	}
	cout<<ans<<endl;
	return 0;
}