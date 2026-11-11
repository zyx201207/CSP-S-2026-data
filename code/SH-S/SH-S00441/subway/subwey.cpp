#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=505;
int c,n,m,d,q,w[N],k[N],a[N][50005],t[N][50005];
int main(){
	freopen("subwey1.in","r",stdin);
	freopen("subwey.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][k[i]]>>t[i][k[i]];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<1LL*x*y<<endl; 
	}
	return 0;
}

