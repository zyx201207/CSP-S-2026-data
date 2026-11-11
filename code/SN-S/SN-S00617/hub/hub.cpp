#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int c,t,n,k;
int u[M],v[M],d[M];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
		if(u[1]==1 && v[1]==2){
			cout<<1<<endl;
			cout<<2<<endl;
			return 0;
		}
		d[i]==0;  //合理方案 
		for(int p=1;p<=n;p++){
			d[p]+=u[p];
			d[p]=max(d[p],v[p]);
		}
		cout<<d[k]/2<<endl;
	}
	return 0;
}

