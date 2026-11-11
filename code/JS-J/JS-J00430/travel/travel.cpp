#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool flag=true,fl=true;
    for(int i=0;i<c1.size();i++)
    {
        if(c1[i]!=c2[i])
        {
            flag=false;
            fl=false;
            cout<<"0000";
            return 0;
        }
    }
    cout<<1;
    for(int i=0;i<s1.size()-1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=false;
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    char k=s1[s1.size()-1];
    char m=s2[s2.size()-1];
    if(k=='F'&&m!='D'||k=='D'&&m!='F'||m=='D'&&k!='F'||m=='F'&&k!='D')
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(k=='A'&&m=='B'||k=='B'&&m=='A'||k=='B'&&m=='C'||k=='C'&&m=='B'||k=='D'&&m=='F'||k=='F'&&m=='D')cout<<1;
    else cout<<0;
    return 0;
}
