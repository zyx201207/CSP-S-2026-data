#include <bits/stdc++.h> 
using namespace std;
string a,b,id1,id2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>id1>>a>>id2>>b;
	if (id1=="01" || id2=="01" || id1=="16" || id2=="16"){
		cout<<"0000";
	}
	else{
		if (id1!=id2){
			cout<<"0000";
			return 0;
		}
		else{
			cout<<"1";
			if (a[1]==b[1] && a[0]==b[0]){
				cout<<"1";
				if (a[2]<='C' && b[2]<='C'){
					cout<<"1";
					if((a[2]=='A'&&b[2]=='B')||(a[2]=='C'&&b[2]=='B')){
						cout<<"1";
						return 0;
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else if (a[2]>='D'&&a[2]<='E' && b[2]>='D'&&b[2]<='E'){
					cout<<"1";
					if((a[2]=='D'&&b[2]=='E')){
						cout<<"1";
					}
					else{
						cout<<"0";
						return 0;
					}	
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else{
				cout<<"000";
				return 0;
			}
		}
	}
	return 0;
}
