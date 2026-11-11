#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?1:0);
	string t1="",t2="";
	for(int i=0;i<=1;i++) t1+=s1[i],t2+=s2[i];
	cout<<(c1==c2&&t1==t2?1:0);
	cout<<(c1==c2&&t1==t2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='A'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))?1:0);
	cout<<(c1==c2&&t1==t2&&((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F'))?1:0);
	return 0;
}
