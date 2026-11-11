#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int c,n,m,d,q;
int w[N],a[N],t[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int i=1;i<=k;i++)cin>>a[i]>>t[i];
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
	}
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
}
