#include<bits/stdc++.h>
using namespace std;
int v1,v2,v3,v4;
string a1,s1,a2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		v1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			v2=1;
			if(s2[2]=='D'&&s1[2]=='F'||s2[2]=='F'&&s1[2]=='D'||s2[2]=='A'&&(s1[2]=='B'||s1[2]=='C')
			||s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C')||s2[2]=='C'&&(s1[2]=='B'||s1[2]=='A')){
				v3=1;
				if(char(s2[2]+1)==s1[2]||char(s2[2]-1)==s1[2])v4=1;
			}
		}
	}
	cout<<v1<<v2<<v3<<v4;
	return 0;
}