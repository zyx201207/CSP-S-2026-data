#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;
	scanf("%lld%lld",&n,&k);
	vector<int>a(n+2,0);
	vector<bool>flag(n+2,false);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int ans=0;
	for(int j=31;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++)if(!flag[i]){
			if((a[i]&(1<<j))!=0){
				cnt++;
			}
		}	
		if(cnt<k){
			continue;
		}
		ans+=(1<<j);
		for(int i=1;i<=n;i++)if(!flag[i]){
			if((a[i]&(1<<j))==0){
				flag[i]=true;
			}
		}
	}
	printf("%lld",ans);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
