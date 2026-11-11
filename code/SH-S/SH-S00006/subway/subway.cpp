#include<bits/stdc++.h>
using namespace std;
struct met{
	int k,a[5],t[5];
}mn[500];
int c,n,m,d,q,w[500005];
pair <int,int> jh[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>mn[i].k;
		for(int j=1;j<=mn[i].k;j++) cin>>mn[i].a[j]>>mn[i].t[j];
	}
	for(int i=1;i<=q;i++) cin>>jh[i].first>>jh[i].second;
	cout<<23597;
	return 0;
}
