#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool c(string x){
	if(x[2]=='A'||x[2]=='B'||x[2]=='C')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(c(s1)==c(s2)){
				int t1=s1[2]-'A',t2=s2[2]-'A';
				if(abs(t1-t2)==1)cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
}
//gugugaga gugugaga gugugaga!!!
