#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1=s1.substr(0,2),p2=s2.substr(0,2);
	if(stoi(c1)==stoi(c2)){
		if(stoi(p1)==stoi(p2)){
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				if(s1[2]=='F')s1[2]='E';
				if(s2[2]=='F')s2[2]='E';
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2])cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
} 
