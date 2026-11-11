#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		if(c[0]!=d[0]||c[1]!=d[1]){
			cout<<"1000";
			return 0;
		}
		else{
			if((c[2]<='C'&&d[2]>='D')||(c[2]>='D'&&d[2]<='C')){
				cout<<"1100";
				return 0;
			}
			else{
				if((c[2]=='A'&&d[2]=='C')||(c[2]=='C'&&d[2]=='A')){
					cout<<"1110";
					return 0;
				}
				else cout<<"1111";
			}
		}
	}
}