#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0,maxn=-1,maxlast=-1;
	while(maxn<=m){
		maxlast=cnt-1;
		ans=0;
		for(int i=1;i<=cnt;i++){
			ans+=a[cnt]-a[i];
		}
		cnt++;
		maxn=max(maxn,ans);
	}
	cout<<maxlast;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
