#include <bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[4],s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2];
	cin>>s1[1]>>s1[2]>>s1[3];
	cin>>c2[1]>>c2[2];
	cin>>s2[1]>>s2[2]>>s2[3];
    if(c1[1]!=c2[1]||c1[2]!=c2[2])cout<<"0000";
	else{
		if(s1[1]!=s2[1]||s1[2]!=s2[2])cout<<"1000";
		else{
			if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C'){
				if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
					if(s1[3]=='A'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='A'){
						cout<<"1110";
					}else cout<<"1111";
				}else cout<<"1000";
			}else{
				if(s2[3]=='D'||s2[3]=='F')cout<<"1111";
				else cout<<"1000";
			}
		}
	}
	return 0;
}
