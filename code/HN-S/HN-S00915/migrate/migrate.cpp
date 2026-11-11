#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	for(;t>=0;t--){
		int n,d,i,j,t=0;
		cin>>n>>d;
		int x[n];
		for(i=0;i<n;i++)
			cin>>x[i];
		if(d<2*(x[1]-x[0])){
			cout<<"0"<<endl;
		}
		else{
			int w=d%(x[1]-x[0]);
			for(j=0;j<n;j++){
			int o=n;
			if(n<w+2+j){
			break;}
			else{
				o=o-(w+j);
				t=t+o/w;
			}
			}
		cout<<t<<endl;	}
	}
	return 0;
}
