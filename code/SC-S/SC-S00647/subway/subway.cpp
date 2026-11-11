#include<bits/stdc++.h>
using namespace std;
int w[500010];
struct rou{
	int a;
	int t;
};
rou rout[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++)cin>>rout[j].a>>rout[j].t;
	}
	for(int i=1;i<=q;i++){
		int st,en;cin>>st>>en;
		cout<<w[st]+w[en]+2*rout[1].t<<endl;
	}
	return 0;
}
