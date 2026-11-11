#include<bits/stdc++.h>
using namespace std;
int n,m,a[3],b[3],ax,bx,ah,bh;
string ss,xx;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>n>>ss>>m>>xx;
    if(n!=m)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<"1";
        for(int i=0;i<=1;i++)
        {
            a[i]=ss[i]-'0';
            b[i]=xx[i]-'0';
        }
        ax=a[0]*10+a[1];
        bx=b[0]*10+b[1];
        ah=ss[2]-'A';
        bh=xx[2]-'A';
        if(ax!=bx)
        {
            cout<<"000";
            return 0;
        }
        else
        {
            cout<<"1";
            if(ah<=2&&bh>2||bh<=2&&ah>2)cout<<"00";
            else
            {
                cout<<"1";
                if(ah==0&&bh==2||ah==2&&bh==0)cout<<"0";
                else cout<<"1";
            }
        }
    }
}
