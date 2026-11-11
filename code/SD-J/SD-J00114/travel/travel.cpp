#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	char r=s1[2],x=s2[2];
	if(c1==c2)b1=1;
	if(b1&&(s1.substr(0,2)==s2.substr(0,2)))b2=1;
	if(b1&&b2&&(s1[2]<'D'&&s2[2]<'D'||s1[2]>='D'&&s2[2]>='D'))b3=1;
	if(b1&&b2&&b3&&(abs(r-x)==1||abs(r-x)==2&&r=='D'))b4=1;
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
//½¨Òé½µºì

