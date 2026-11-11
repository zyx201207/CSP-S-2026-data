#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(b[2]<='C'&&d[2]<='C'){
				cout<<"1";
				if(b[2]!='B'&&d[2]!='B'){
					cout<<"0\n";
				}
				else{
					cout<<"1\n";
				}
			}
			else if(b[2]>='D'&&d[2]>='D'){
				cout<<"11\n";
			}
			else{
				cout<<"00\n";
			}
		}
		else{
			cout<<"000\n";
		}
	}
	else{
		cout<<"0000\n";
	}
	return 0;
}
