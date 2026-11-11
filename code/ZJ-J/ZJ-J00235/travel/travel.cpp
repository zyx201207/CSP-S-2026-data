#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
string a,b,q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>q>>w;
	if(a==q){
		cout<<"1";
		if(b[0]==w[0]&&b[1]==w[1]){
			cout<<"1";
			if(b[2]>='D'&&w[2]>='D'){
				cout<<"11";
			}else if(b[2]<='C'&&w[2]<='C'){
				cout<<"1";
				if(w[2]-b[2]==1||b[2]-w[2]==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}		
		}else{
			cout<<"000";
		}		
	}else{
		cout<<"0000";
	}


	return 0;
}