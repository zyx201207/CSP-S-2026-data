#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>a>>b;
	if(x==a){
		if(y[0]==b[0] && y[1]==b[1]){
			if((b[2]>='D' && y[2]>='D') || (b[2]<='C' && y[2]<='C')){
				if(abs(b[2]-y[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
