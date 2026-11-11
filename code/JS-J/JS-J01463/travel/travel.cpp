#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        int ss1=(s1[0]-'0')*10+s1[1]-'0',sss1=s1[2]-'A',ss2=(s2[0]-'0')*10+s2[1]-'0',sss2=s2[2]-'A';
        if(ss1==ss2)
        {
            cout<<1;
            if((sss1>=0&&ss1<=2&&sss2<=2&&sss2>=0)||(sss1>2&&sss1<5&&sss2>2&&sss2<5))
            {
                cout<<1;
                if(abs(sss1-sss2)==1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
