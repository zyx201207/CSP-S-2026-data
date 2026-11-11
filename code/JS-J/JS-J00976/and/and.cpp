#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
const int N=2e5+5;
int a[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i!=j) ans=max(ans,(a[i]& a[j]));
			}
		}cout<<ans;
		return 0;
	}if (m==1){
		for (int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans;
		return 0;
	}if (n==m){
		ans=a[1];
		for (int i=2;i<=n;i++) ans=(a[i] & ans);
		cout<<ans;
		return 0;
	}for (int i=1;i<=n;i++){
		ans=min(ans,a[i]);
	}cout<<ans;
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
