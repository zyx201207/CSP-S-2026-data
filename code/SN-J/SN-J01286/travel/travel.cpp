#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1a,s2a,s1b,s2b;
	char s1c,s2c;
	cin>>s1a>>s1b>>s1c>>s2a>>s2b>>s2c;
	if(s1a==s2a){
		cout<<1;
		if (s1b==s2b){
			cout<<1;
			if ((s1c<='C'&&s2c<='C')||(s1c>'C'&&s2c>'C')){
				cout<<1;
				if (abs(s1c-s2c)==1){
					cout<<1;
				}
				else {
					cout<<0;
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
