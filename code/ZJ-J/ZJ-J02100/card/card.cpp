//T4 card 解法1 预期100
//Trick||Treat!
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],last[300010],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans[1]++;
			else ans[2]++;
		}
		if(a[n]==1) ans[1]=n;
		else ans[2]=n;
		cout<<ans[1]<<" "<<ans[2];
		return 0;
	}
	for(int i=1;i<=n;i++) last[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=last[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}