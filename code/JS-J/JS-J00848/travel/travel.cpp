#include<bits/stdc++.h>
using namespace std;
int t[100];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,s,d,f;
    cin>>a>>s>>d>>f;
    t['A']=1;
    t['B']=1;
    t['C']=1;
    t['D']=2;
    t['F']=2;
    if((a[0]-'0')*10+(a[1]-'0')==(d[0]-'0')*10+(d[1]-'0'))
    {
        cout<<'1';
        if((s[0]-'0')*10+s[1]==(f[0]-'0')*10+f[1])
        {
            cout<<'1';
            if(t[s[2]]==t[f[2]])
            {
                cout<<'1';
                if(abs(s[2]-f[2])==1)
                    cout<<'1';
                else
                    cout<<'0';
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
    cout<<"0000";
    return 0;
}
