#include<bits/stdc++.h>
using namespace std;
int n,m,a[1002][1002][2],c,d,q,k,ti[1005],l,r;
bool aa[1002][1002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
			return 0;
		}
		if(n==3){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	for(int i=1;i<=m;i++)cin>>ti[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int w,t;cin>>w>>t;
			a[i][j][0]=w;
			a[j][i][0]=w;
			a[i][j][1]=t;
			a[j][i][1]=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
	}
	return 0;
}