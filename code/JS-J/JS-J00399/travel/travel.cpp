#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string l1,l2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    else
    {
        cout<<1;
        for(int i=0;i<3;i++)
        {
            if(isdigit(s1[i]))l1+=s1[i];
            if(isdigit(s2[i]))l2+=s2[i];
        }
        if(l1!=l2)
        {
            cout<<"000"<<endl;
            return 0;
        }
        else
        {
            cout<<1;
            if((s1[2]>='A'&&s1[2]<='C'&&(s2[2]=='D'||s2[2]=='F'))||(s2[2]>='A'&&s2[2]<='C'&&(s1[2]=='D'||s1[2]=='F')))
            {
                cout<<"00"<<endl;
                return 0;
            }
            else
            {
                cout<<1<<((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F'))<<endl;
            }
        }
    }
    return 0;
}
