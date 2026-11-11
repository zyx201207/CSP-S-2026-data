#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],k[N],t[N],w[N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k[i];i++){
			cin>>a[i]>>t[i];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl; 
	}
	return 0;
}
