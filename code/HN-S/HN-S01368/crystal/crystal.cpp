#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int sum=0,t=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			t++;
			if(sum>m){
				ans=max(ans,t-1);
				break;
			}
			else if(sum==m){
				ans=max(ans,t);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

