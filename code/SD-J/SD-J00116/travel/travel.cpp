#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool f=1;
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i])f=0;
	}
	if(f){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2)){
				cout<<"1";
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1||(s1[2]-'A'>2&&s2[2]-'A'>2))cout<<"1";
				else cout<<"0";
			}
			else {
				cout<<"00";
				return 0;
			}
			
		}
		else {
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
	return 0;
} 
