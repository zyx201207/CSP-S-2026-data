#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int main() 
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int m,n;
	if(c1[0]=c2[0]&&c1[1]==c2[1]) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F') n=1;
	else n=2;
	if(s2[2]=='D'||s2[2]=='F') m=1;
	else m=2;
	if(n==m) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(s2[2]+1==s1[2]||s1[2]+1==s2[2])cout<<1;
	else cout<<"0";
	return 0;
}
