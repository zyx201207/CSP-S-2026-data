#include<bits/stdc++.h>
using namespace std;
int c1,c2;string s1,s2;bool f1=0,f2=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int line1=10*(s1[0]-'0')+(s1[1]-'0'),line2=10*(s2[0]-'0')+(s2[1]-'0');

    if(line1==line2){
		cout<<1;
		f1=1;
		}
    else cout<<0;

    if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]!='F'&&s2[2]!='F'&&s1[2]!='D'&&s2[2]!='D')&&f1)
	{
		cout<<1;
		f2=1;
	}
    else cout<<0;

    if(((s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C'))&&abs(s1[2]-s2[2])==1&&f1&&f2)cout<<1;
    else cout<<0;

    return 0;

}
