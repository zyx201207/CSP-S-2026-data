#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string t1,t2,s1,s2,near[6]={"AB","BC","DF","BA","CB","FD"};
    cin>>t1>>s1>>t2>>s2;
    if(t1==t2)
    {
        cout<<1;
        if(s1.size()==s2.size()&&
           ((s1.size()==2&&s1[0]==s2[0])
            ||(s1.size()==3&&s1[0]==s2[0]&&s1[1]==s2[1])))
        {

            cout<<1;
            if((s1.back()<='C'&&s2.back()<='C')||(s1.back()>='D'&&s2.back()>='D'))
            {
                cout<<1;
                int flag=0;
                for(string s:near)
                {
                    if((s1.back()==s[0])&&(s2.back()==s[1]))flag=1;
                }
                if(flag==1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
