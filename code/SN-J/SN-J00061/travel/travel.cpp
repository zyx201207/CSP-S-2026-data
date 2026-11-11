#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1a,s1b,s1c,s2a,s2b,s2c;
	string c1,s1,c2,s2;
	cin>>c1>>s1a>>s1b>>s1c>>c2>>s2a>>s2b>>s2c;
	if(c1==c2){
		cout<<1;
		if(s1a==s2a){
			cout<<1;
			if(s1b==s2b){
				cout<<1;
				if(s1c=='D' and s2c=='F' or s1c=='A' and s2c=='B' or s1c=='B' and s2c=='C' or s1c=='A' and s2c=='C' or   s2c=='D' and s1c=='F' or s2c=='A' and s1c=='B' or s2c=='B' and s1c=='C' or s2c=='A' and s1c=='C'){
					cout<<1;
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
	else
		cout<<"0000"; 
return 0;

}
