#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	r1=(c1[0]-'0')*10+(c1[1]-'0');
	x1=(c2[0]-'0')*10+(c2[1]-'0');
	if(r1==x1)cout<<1;
	else cout<<0;
	r2=(s1[0]-'0')*10+(s1[1]-'0');
	x2=(s2[0]-'0')*10+(s2[1]-'0');
	if(r2==x2&&r1==x1)cout<<1;
	else cout<<0;
	if(s1[2]=='F'&&s2[2]!='D'||s1[2]=='D'&&s2[2]!='F')cout<<0;
	else if((s1[2]=='D'&&s2[2]!='C')||(s2[2]=='C'&&s1[2]!='D'))cout<<1;
	else cout<<0;
	if(r2==x2&&((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1))&&((s1[2]=='C'&&s2[2]!='D')||(s1[2]=='D'&&s2[2]!='C')))cout<<1;
	else cout<<0;
	return 0;
}
