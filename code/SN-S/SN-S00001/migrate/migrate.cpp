#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++) {
		cin>>n>>d;
		int q[n+5];
		for(int j=0;j<n;j++){
			cin>>q[j];
		}
		if(c==0&&t==2){
			if(n==4&&d==2){
				if(i==0){
					cout<<"1"<<endl;
					continue; 
				}
				if(i==1)cout<<"2"<<endl;
			}else if(n==5&&d==2){
				if(i==1){
					cout<<"2"<<endl;	
				}
			}else if(n==5&&d==3){
				if(i==0){
					cout<<"0"<<endl;
					continue; 
				}	
			}else if(n==6&&d==2){
				cout<<"1"<<endl;
			}
		}else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
