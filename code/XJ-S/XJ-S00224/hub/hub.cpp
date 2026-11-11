#include <bits/stdc++.h>
using namespace std;
int c,T,a[500010],b[500010];
void solve(){
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
} 
