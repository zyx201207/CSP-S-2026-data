#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool a=c1!=01&&c1!=16&&c2!=01&&c2!=16;
    if(c1==c2&&a) cout<<"1";
    else cout<<"0";
    if(s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2&&a) cout<<"1";
    else cout<<"0";
    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'&&a) cout<<"11";
    else if((s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')&&a) cout<<"11";
    else if((s1[2]=='E'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='E')&&a) cout<<"11";
    else if((s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')&&a) cout<<"10";
    else cout<<"00";
	return 0;

}
