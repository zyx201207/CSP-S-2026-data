#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1;
	string a2;
	string b1;
	string b2;
	int a=0,b=0;
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')a++;
	if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')b++;
	if(a1==b1){
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			if(a==b){
				if(a2[2]=='B'||b2[2]=='B'){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
