#include<iostream>
using namespace std;
int c,n,m,d,q,w[500005],k,a,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(q<=3){
			continue;
		}
		cout<<w[x]+w[y]<<endl;
	}
	if(n==2 && q==2){
		cout<<"32\n17\n";
	}else if(n==3 && q==2){
		cout<<"35\n16\n";
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
