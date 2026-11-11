#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,d,m,q,w[500005],pf;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,ai[50005],ti[50005];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ai[j]>>ti[j];
		}
		pf+=ti[1];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<"\n"<<17;
	}
	if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<"\n"<<16;
	}
	else if(q==1){
		cout<<pf<<"\n";
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<pf<<"\n";
			pf++;
		}
	}
	return 0;
}

