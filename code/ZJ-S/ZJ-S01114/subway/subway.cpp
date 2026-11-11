#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[555];
long long k[555];
long long t[222][444];
long long p[222],o[222];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long a,b;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>b;
			t[j][a]=b;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>p[i]>>o[i];
		ans+=w[p[i]]+w[o[i]];
		cout<<ans+t[i][2]+t[i][3]<<endl;
	}
	return 0;
}