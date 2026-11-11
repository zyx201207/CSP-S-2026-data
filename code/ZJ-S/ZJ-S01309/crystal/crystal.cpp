#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;long long n,m,a[N],sum[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int tot=1;for(int i=1;i<=n;i++){
		while(tot<i&&a[i]*(i-tot+1)-(sum[i]-sum[tot-1])>m) tot++;
		ans=max((int)ans,i-tot+1);
	}cout<<ans;
	return 0;
}
