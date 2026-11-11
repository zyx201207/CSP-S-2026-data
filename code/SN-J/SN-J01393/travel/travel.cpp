#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<"1";
		if(c[1]==d[1]){
			cout<<"1";
			if((c[2]-'A'<='C'-'A' && d[2]-'A'<='C'-'A') || (c[2]-'A'>='D' && d[2]-'A'>='D')){
				cout<<"1";
				if(c[2]-d[2]==1 || c[2]-d[2]==-1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
