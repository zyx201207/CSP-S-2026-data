#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int a,b,c,d;
	char E,F;
	cin>>a>>b>>c>>d>>E>>F;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<"1";
		if((E-'A'-2<=0)!=(F-'A'-2<=0)){
			cout<<"00";
		}else{
			cout<<"1";
			if((E-F)!=1){
				cout<<"0";
			}else{
				cout<<"1";
			}
		}
	}
	return 0;
} 
