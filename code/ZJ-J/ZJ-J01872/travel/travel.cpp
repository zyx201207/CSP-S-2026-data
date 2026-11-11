#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,y,i,fl;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>x>>s1>>y>>s2;
	fl=1;
	if(x==y) cout<<"1";
	else cout<<"0",fl=0;
	for(i=0;i<=1;i++)
	  if(s1[i]!=s2[i]){
	  	fl=0;
	  	break;
	  }
	if(fl) cout<<"1";
	else cout<<"0";
	if(!fl) cout<<"0";
	else 
	if(s1[2]>='A'&&s1[2]<='C'){
		if(s2[2]>='A'&&s2[2]<='C') cout<<"1";
		else cout<<"0",fl=0;
	}
	else
	  if(s2[2]>='D'&&s2[2]<='F') cout<<"1";
	  else cout<<"0",fl=0;
	if(!fl) cout<<"0";
	else {
		if(s1[2]=='A'&&s2[2]=='B') cout<<"1";
		else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) cout<<"1";
		else if(s1[2]=='C'&&s2[2]=='B') cout<<"1";
		else if(s1[2]=='D'&&s2[2]=='F') cout<<"1";
		else if(s1[2]=='F'&&s2[2]=='D') cout<<"1";
		else cout<<"0";
	}
	return 0;
}