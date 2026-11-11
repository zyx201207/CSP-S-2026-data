#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	for(int i=0;i<=2;i++){
		if(b[i]>='1' && b[i]<='18' && d[i]>='1' && d[i]<='18' && b[i]!=d[i]){
			if(b[1]==d[1] && b[2]==d[2]){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	for(int i=0;i<=2;i++){
		if(b[i]>='A' && b[i]<='C' && d[i]>='A' && d[i]<='C' && b[i]!=d[i]){
			cout<<"1";
		}else{
		    cout<<"0";
		}
	}
	return 0;
} 
