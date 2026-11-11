#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,s;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=stoi(s1.substr(0,2));
	a2=stoi(s2.substr(0,2));
	s=s1[2];
	s+=s2[2];
	sort(s.begin(),s.end());
    if(c1==c2){
    	cout<<1;
    	if(a1==a2){
    		cout<<1;
    		if(s[0]=='A'||s[0]=='B'||s[0]=='C'){
    			if(s[1]=='A'||s[1]=='B'||s[1]=='C'){
    				cout<<1;
    				if(s[0]+1==s[1]&&s[0]!='C') cout<<1;
    				else cout<<0;
				}
				else cout<<"00";
			}
			else{
				if(s=="DF") cout<<"11";
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
