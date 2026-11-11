#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b) cout<<1;
	else cout<<0;
	int c1=s1[1]-'0'+(s1[0]-'0')*10,c2=s2[1]-'0'+(s2[0]-'0')*10;
	if(c1==c2 && a==b) cout<<1;
	else cout<<0;
	if((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C') && c1==c2 && a==b) cout<<1;
	else if(((s1[2]=='D' && s2[2]=='E') || (s1[2]=='E' && s2[2]=='D')) && c1==c2 && a==b) cout<<1;
	else cout<<0;
	if((s1[2]-s2[2]==1 || s1[2]-s2[2]==-1) && !(s1[2]=='D' && s2[2]=='C') && !(s1[2]=='C' && s2[2]=='D') && c1==c2 && a==b) cout<<1;
	else cout<<0;
	return 0;
}
