#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],k,a[N],t[N],msx;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=k;i++){
		if(t[i]!=t[i-1]){
			msx=1;
		}
	}
	if(msx!=1){
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<abs(x-y)*t[1]<<'\n';
		}
	}
	
	return 0;
}
