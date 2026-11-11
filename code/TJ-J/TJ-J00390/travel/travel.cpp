#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=0,f1=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		f1=0;
	}
	
	if(s1[0]==s2[0] && s1[1]==s2[1] && f1) cout<<1;
	else cout<<0;
	
	if(s1[0]==s2[0] && s1[1]==s2[1] && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')) && f1){
		cout<<1;
		f=1;
	}
	else cout<<0;
	
	int l1=s1[2]-'0';
	int l2=s2[2]-'0';
	if(max(l1,l2)-min(l1,l2)==1 && f && f1) cout<<1;
	else cout<<0;
	return 0;
} 
