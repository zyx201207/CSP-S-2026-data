#include<bits/stdc++.h>
using namespace std;
map<char,int>l,r;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,a1,a2;
    cin>>s1>>s2>>a1>>a2;
    r['A']=1;r['B']=2;r['C']=3;
    l['D']=1;l['F']=2;
    if(s1==a1)
    {
        if(s2[0]==a2[0]&&s2[1]==a2[1])
        {
            if(r.count(s2[2])&&r.count(a2[2]))
            {
                if(r[s2[2]]+1==r[a2[2]]||r[s2[2]]-1==r[a2[2]])
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else if(l.count(s2[2])&&l.count(a2[2]))
            {
                if(l[s2[2]]+1==l[a2[2]]||l[s2[2]]-1==l[a2[2]])
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

