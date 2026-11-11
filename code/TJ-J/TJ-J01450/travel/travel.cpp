#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[1]!=c[1]){
		cout<<"0000";
	}else{
		cout<<'1';
		if(b[1]!=d[1]){
			cout<<"000";
		}else{
			cout<<"1";
			if(b[2]-'A'<5&&b[2]-'A'>2&&d[2]-'A'<5&&d[2]-'A'>2){
				cout<<"11";
			}else{
				if(b[2]-'A'<3&&d[2]-'A'<3){
					cout<<'1';
					if(d[2]-b[2]==1||b[2]-d[2]==1){
						cout<<'1';
					}else{
						cout<<'0';
					}
				}else{
					cout<<"00";
				}
			}
		}
	}
	return 0;
} 
