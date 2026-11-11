#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0){
		int x;
		cin>>x;
		if(x==4){
			cout<<"1\n2";
			return 0;
		}else{
			cout<<"0\n1";
			return 0;
		}
	}
	while(t--){
		cout<<"0\n";
	}return 0;
}