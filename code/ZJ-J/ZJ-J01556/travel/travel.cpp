#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string x1,x2;
	cin>>c1>>x1>>c2>>x2;
	if(c1==c2){
		cout<<1;
		if(x1[1]==x2[1]){
			cout<<1;
			if((x1[2]<='C'&&x2[2]<='C')||(x1[2]>'C'&&x2[2]>'C')){
				cout<<1;
				if(x1[2]<='C'&&x2[2]<='C'){
					if(x1[2]=='B'||x2[2]=='B'){
						cout<<1;
					}
					else cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}