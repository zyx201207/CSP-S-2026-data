#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,w[N],k[505],x[N],y[N];
vector<long long> a[505],t[505];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int aa,tt;
            cin>>aa>>tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
        }
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	return 0;
}
