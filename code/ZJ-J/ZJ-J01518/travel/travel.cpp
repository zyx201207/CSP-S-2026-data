#include<bits/stdc++.h>
using namespace std;
string s1,s2,b1,b2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>s1>>s2>>b1>>b2;
	if(s1==b1){
		if(s2[0]==b2[0]&&s2[1]==b2[1]){
			if(s2[2]=='A'&&b2[2]=='B'||s2[2]=='A'&&b2[2]=='C'||s2[2]=='B'&&b2[2]=='C'||b2[2]=='A'&&s2[2]=='B'||b2[2]=='A'&&s2[2]=='C'||b2[2]=='B'&&s2[2]=='C'||s2[2]=='D'&&b2[2]=='F'||b2[2]=='D'&&s2[2]=='F')	
			{
				if(s2[2]=='A'&&b2[2]=='B'||b2[2]=='A'&&s2[2]=='B'||s2[2]=='B'&&b2[2]=='C'||s2[2]=='C'&&b2[2]=='B'||s2[2]=='D'&&b2[2]=='F'||s2[2]=='F'&&b2[2]=='D')
					cout<<"1111";
				else
					cout<<"1110";
			
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}