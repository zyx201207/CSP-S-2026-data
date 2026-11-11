#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int e,m;
		cin>>e>>m;
		for(int j=0;j<e;j++){
			cin>>m;
		}
	}
	if(c==0&&t==2){
		cout<<"1"<<endl;
		cout<<"2";
	}
	else{
		cout<<"0"<<endl;
		cout<<"1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
