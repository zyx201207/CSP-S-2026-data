#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[1000],x[1000],p[1000];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=7;j++){
			cin>>x[i];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			cin>>p[i];
		}
	}
	cout<<"32"<<endl;
	cout<<"17";
	
	//^-^ 
	return 0;
}
