#include<bits/stdc++.h>
using namespace std;
int k;
string c1,s1,c2,s2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])) cout<<1;
    else cout<<0;
    if((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))) cout<<1;
    else cout<<0;
    k=s1[2]-s2[2];
    if((c1==c2)&&(s1[0]==s2[0]&&s1[1]==s2[1])&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&(abs(k)<=1)) cout<<1;
    else cout<<0;
	return 0;
}