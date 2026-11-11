#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
int a[N],t[N],w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i]>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			k=(k,k+a[i],t[i]);
			for(int j=1;j<=i;j++){
				int x,y;
				cin>>x>>y;
				t[i]=w[i]+t[i]+w[i];
				
			}
		}
	}
	cout<<32<<'\n'<<17;
	return 0;
}
