#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]=='A'||'B'||'C'&&s2[2]=='A'||'B'||'C')||(s1[2]=='D'||'E'&&s2[2]=='D'||'E'))&&(s1[2]||s2[2]=='A'||'B')||(s1[2]||s2[2]=='C'||'B')||(s1[2]||s2[2]=='D'||'e')){
	cout <<"1111";	
	}
    else if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]=='A'||'B'||'C'&&s2[2]=='A'||'B'||'C')||(s1[2]=='D'||'E'&&s2[2]=='D'||'E'))){
		cout<<"1110";
	}
	else if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"1100";
	}
	else if(c1==c2){
	
		cout<<"1000";	
	}

	
	
	return 0;
}
