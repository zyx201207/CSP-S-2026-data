#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[1000001],ans,app[10001][10001],apl[100001];
struct Point{
	long long a;
	vector<int> b,son;
}node[1000001];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ax;
		cin>>ax;
		for(int j=1;j<=ax;j++){
			int xx,yy;
			cin>>xx>>yy;
			apl[xx]+=yy;
		}
	}
	for(int i=1;i<=q;i++){
		int lo,ol;
		cin>>lo>>ol;
		int ans=a[lo]+a[ol];
		for(int j=lo;j<=ol;j++){
			ans+=apl[j];
		}
			cout<<ans<<'\n';
	}
}
