#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,sum=0,lst=1;
	for(int i=1;i<=n;i++){
		int need=(a[i]-a[i-1])*(i-lst);
		while(lst<i&&sum+need>m){
			need-=(a[i]-a[lst]);
			lst++;
		}
		sum+=need;
		ans=max(ans,i-lst+1);
//		cout<<i<<" "<<lst<<"\n";
	}
	cout<<ans;
	return 0;
}

