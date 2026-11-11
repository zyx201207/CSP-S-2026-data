#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],a[500005],t[500005],k[500005],xr,yr,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	cin>>q;
	while (q--){
		cin>>xr>>yr;
		ans=0;
		ans+=w[xr]+w[yr];
		ans+=(yr-xr)*t[1];
		cout<<ans;
	}
	return 0;
}
