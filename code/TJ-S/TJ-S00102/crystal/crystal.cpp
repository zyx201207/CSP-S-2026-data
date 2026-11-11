#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxx = -1e9;
	for(int i = 2;i<=n;i++){
		int cnt = 0,flag = 0,ans = 0;
		for(int j = i;j>=1;j--){
			if(cnt+a[i]-a[j] > m){
				flag = 1;
				break;
			}
			cnt+=a[i]-a[j];
			ans++;
			
		}
		if(flag == 1)continue;
		maxx = max(ans,maxx); 
	}
	cout<<maxx;
	return 0;
}
