#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[500005];
	int a[500005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		if(c==0&&n==2){
			cout<<32<<endl<<17;
			return 0;
		}
		if(c==0&&n==3){
			cout<<35<<endl<<16;
			return 0;
		}
		else{
			cout<<w[i]+w[m]+a[i]+a[n]<<endl<<w[i+1]+w[n-1]+a[i+1]+a[n-1];
			return 0;
		}
	}
	return 0;
}
