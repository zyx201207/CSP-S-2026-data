#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500050],ans,s=1,e=2,shang,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(e!=n){
		cnt+=(e-s)*(a[e]-a[e-1]);
		while(cnt>m){
			cnt-=a[e]-a[s];
			s++;
		}
		ans=max(ans,e-s+1);
		e++;
	}
	cout<<ans;
	return 0;
}