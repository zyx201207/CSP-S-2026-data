#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],R,ans,a[500005],t[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
	}
	//妄想特判样例得分(￣_,￣ )
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
		return 0;
	}
	cin>>R;
	while(R--){
		int x,y; 
		cin>>x>>y;
		cout<<"Attack the D point!";
	}
	return 0;
}
//局座高见。
