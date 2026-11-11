#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;

string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"1000";
	else if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')) cout<<"1100";
	else if(int(s1[2])+1==int(s2[2])||int(s1[2])-1==int(s2[2])||s1[2]=='D'||s1[2]=='F') cout<<"1111";
	else cout<<"1110";
	
	return 0;
}

