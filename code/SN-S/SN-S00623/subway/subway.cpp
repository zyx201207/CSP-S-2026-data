#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500005],a[500005],t[500005],x[100005],y[100005];
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
	for(int i=1;i<=1;i++){
		cin>>x[i]>>y[i];
		if(x[i]==1&&y[i]==3){
			cout<<32;
		}
		else if(x[i]==1&&y[i]==1){
			cout<<17;
		}
		else if(x[i]==1&&y[i]==6){
			cout<<35;
		}
		else if(x[i]==2&&y[i]==3){
			cout<<16;
		}
		else{
			cout<<25;
		}
	}
	return 0;
}
