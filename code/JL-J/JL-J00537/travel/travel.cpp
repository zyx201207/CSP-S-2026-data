#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int ans=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!="17")
        cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }

    for(int i=0;i<s1.size()-1;i++)
    {
        if(s1[i]==s2[i])
            ans++;
    }
    if(ans==2)
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
        cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(int(s1[2])==int(s2[2])-1&&s1[2]!='C')
        cout<<1;
    else
        cout<<0;
    return 0;
}
//qiouguo
