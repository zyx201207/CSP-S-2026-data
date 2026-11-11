#include<bits/stdc++.h>
using namespace std;
char a[5]={'A','B','C','D','F'};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	//if(c[2]=='F')c[2]='E';
	//if(c1[2]=='F')c1[2]='E';
	if(c==c1)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]+s[1]==s1[0]+s1[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s[2]=='A' or s[2]=='B' or s[2]=='C') and (s1[2]=='A' or s1[2]=='B' or s1[2]=='C'))cout<<"1";
	else if((s[2]=='D' or s[2]=='F') and (s1[2]=='D' or s1[2]=='F')){
            cout<<"11";
            return 0;
	}
	else {
		cout<<"00";
		return 0;
	}
	if(s[2]==s1[2]+1 or s[2]==s1[2]-1)cout<<"1";
	else cout<<"0";
	return 0;
}

