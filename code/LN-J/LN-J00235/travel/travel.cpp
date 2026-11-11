

#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

int check(char c)
{
    if(c=='A'||c=='B'||c=='C')return 1;
    return 0;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
            if(check(s1[2])==check(s2[2]))
            {

                cout<<"1";
                if(abs(s1[2]-s2[2])==1)
                {
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    cout<<"\n";
    return 0;
}

/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/
