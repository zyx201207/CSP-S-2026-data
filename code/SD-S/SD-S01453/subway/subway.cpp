#include<bits/stdc++.h>
using namespace std;
#define C ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
struct u{
	int w;
	int a[50005];
	int t[50005];
}p[505];
int main(){
	C
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>p[i].w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>p[i].a[j]>>p[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<p[x].t[1]+p[y].t[1];
	}
}
