#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"1";
		string cp=c2.substr(0,2),sp=s2.substr(0,2);
//		cout<<cp<<" "<<sp;
		if(cp==sp){
			cout<<"1";
			if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"00";
			}else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(c2[2]=='D'||c2[2]=='F')){
				cout<<"00";
			}else{
				cout<<"1";
				if((s2[2]=='A'&&c2[2]=='B')||(s2[2]=='B'&&c2[2]=='C')||(s2[2]=='D'&&c2[2]=='F')){
					cout<<"1";
				}else if((c2[2]=='A'&&s2[2]=='B')||(c2[2]=='B'&&s2[2]=='C')||(c2[2]=='D'&&s2[2]=='F')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}