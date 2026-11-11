#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<"1";
			if(a2[2]=='A'){
				if(b2[2]=='B'){
					cout<<"1";
					cout<<"1";
					return 0;
				}if(b2[2]=='C'){
					cout<<"1";
					cout<<"0";
					return 0;
				}if(b2[2]=='D'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='F'){
					cout<<"0";
					cout<<"0";
					return 0;
				}
			}if(a2[2]=='B'){
				if(b2[2]=='A'){
					cout<<"1";
					cout<<"1";
					return 0;
				}if(b2[2]=='C'){
					cout<<"1";
					cout<<"1";
					return 0;
				}if(b2[2]=='D'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='F'){
					cout<<"0";
					cout<<"0";
					return 0;
				}
			}if(a2[2]=='C'){
				if(b2[2]=='A'){
					cout<<"1";
					cout<<"0";
					return 0;
				}if(b2[2]=='B'){
					cout<<"1";
					cout<<"1";
					return 0;
				}if(b2[2]=='D'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='F'){
					cout<<"0";
					cout<<"0";
					return 0;
				}
			}if(a2[2]=='D'){
				if(b2[2]=='A'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='B'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='C'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='F'){
					cout<<"1";
					cout<<"1";
					return 0;
				}
			}if(a2[2]=='F'){
				if(b2[2]=='A'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='B'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='C'){
					cout<<"0";
					cout<<"0";
					return 0;
				}if(b2[2]=='D'){
					cout<<"1";
					cout<<"1";
					return 0;
				}
			}
		}else{
			cout<<"0";
			cout<<"0";
			cout<<"0";
			return 0;
		}
	}else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	
	return 0;
}

