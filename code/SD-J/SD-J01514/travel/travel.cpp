#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool b=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2) cout<<"1";
	else{
		cout<<"0";
		b=1;
	} 
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&b==0) cout<<1;
	else{
		cout<<0;
		b=1;	
	} 
	if(b==0&&((c1[2]=='F'&&c2[2]=='D')||(c1[2]=='D'&&c2[2]=='F')||((c1[2]=='B'||c1[2]=='A'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')))){
		cout<<1;
	}
	else{
		cout<<0;
		b=1;
	}
	if(b==0&&abs((c1[2]-'A')-(c2[2]-'A'))==1) cout<<1;
	else cout<<0;
	return 0;
}
