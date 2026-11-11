#include<bits/stdc++.h>

using namespace std;

int c1,c2;
string s1,s2;

void Solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				if (s1[2]=='A'&&s2[2]=='B') cout<<"1111";
				else if(s1[2]=='B'&&s2[2]=='A') cout<<"1111";
				else if(s1[2]=='B'&&s2[2]=='C') cout<<"1111";
				else if(s1[2]=='C'&&s2[2]=='B') cout<<"1111";
				else cout<<"1110";
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"1111";
			}
			else {
				cout<<"1100";
				return;
			}
		}
		else{
			cout<<"1000";
			return ;
		}
	}
	else{
		cout<<"0000";
		return ;
	}
	
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	Solve();
	return 0;
} 
