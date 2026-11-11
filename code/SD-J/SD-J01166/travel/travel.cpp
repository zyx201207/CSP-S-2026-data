#include<bits/stdc++.h>
using namespace std;
string c,c2,s,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		cout<<1;
		if(s[0]==s2[0]&&s[1]==s2[1]){
			cout<<1;
			if((s[2]<='C'&&s2[2]<='C')||(s[2]>'C'&&s2[2]>'C')){
				cout<<1;
				if((s[2]=='D'&&s2[2]=='C')||(s[2]=='C'||s2[2]=='D')){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0; 
			}
		}
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}

	return 0;
}
