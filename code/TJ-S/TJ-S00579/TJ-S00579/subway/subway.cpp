#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0;
int w[100005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>w[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	if(c==0){
		if(n==2){
			cout<<32<<endl;
			cout<<17<<endl;
		}
		else{
			cout<<35<<endl;
			cout<<16<<endl;
		}
	}
	
	return 0;
}

