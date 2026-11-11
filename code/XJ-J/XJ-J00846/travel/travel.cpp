#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if (a==x){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if (b[0]==y[0] && b[1]==y[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if (b[2]=='D' || b[2]=='F'){
		if (y[2]=='D' || y[2]=='F'){
			cout<<"11";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if (y[2]<='C'){
			cout<<'1';
			if (b[2]=='A'){
				if (y[2]=='B'){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if (b[2]=='B'){
				cout<<'1';
			}else{
				if (y[2]=='B'){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}