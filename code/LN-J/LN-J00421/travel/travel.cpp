#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        char sss1=s1[2],sss2=s2[2];
        int ff=0;
        for(int i=0;i<2;i++)
        {
            if(s1[i]!=s2[i])ff=1;
        }
        if(ff==0)
        {
            cout<<1;
            int f1=0,f2=0;
            if(sss1=='A'||sss1=='B'||sss1=='C')f1=0;
            else f1=1;
            if(sss2=='A'||sss2=='B'||sss2=='C')f2=0;
            else f2=1;
            if(f1==f2)
            {
                cout<<1;
                if(sss1+1==sss2||sss2+1==sss1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
