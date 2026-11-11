#include<iostream>
using namespace std;

string c1,s1,s2,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"0000";
	else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"1000";
		else{
			if(s1[2]=='A'){
				if(s2[2]=='B') cout<<"1111";
				else if(s2[2]=='C') cout<<"1110";
				else cout<<"1100";
			}else if(s1[2]=='B'){
				if(s1[2]=='A'||s1[2]=='C') cout<<"1111";
				else cout<<"1100";
			}else if(s1[2]=='C'){
				if(s2[2]=='B') cout<<"1111";
				else if(s2[2]=='A') cout<<"1110";
				else cout<<"1100";
			}else if(s1[2]=='D'){
				if(s2[2]=='F') cout<<"1111";
				else cout<<"1100";
			}else{
				if(s2[2]=='D') cout<<"1111";
				else cout<<"1100";
			}
		}
	}
	return 0;
}
