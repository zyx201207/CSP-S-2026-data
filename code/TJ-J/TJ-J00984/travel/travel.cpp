#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]+b[1]==d[0]+d[1]){
			cout<<1;
			if((b[2]-'0'<=19&&d[2]-'0'<=19)||(b[2]-'0'>=20&&d[2]-'0'>=20)){
				cout<<1;
				if((b[2]-'0')-(d[2]-'0')==1||(b[2]-'0')-(d[2]-'0')==-1||(b[2]-'0')+(d[2]-'0')==42){
					cout<<1;
				}
				else{
					cout<<0;
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
