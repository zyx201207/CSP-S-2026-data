#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=0,maxx=0;
	for(int i=1;i<=a[n];i++){
		int ans=0;
		cnt=0;
		for(int j=1;j<=n;j++){
			if(i>a[j]){
				cnt+=(i-a[j]);
				ans++;
			}
			if(a[j]==i) ans++;
			if(cnt>m){
				ans--;
				cnt-=(i-a[j]);
			}
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx;
	return 0;
}