#include<bits/stdc++.h>
using namespace std;
int s[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int cx1,cx2,f=0;
    string zw1,zw2;
    cin>>cx1>>zw1>>cx2>>zw2;
    int pai1=zw1[0]-'0'+zw1[1]-'0',pai2=zw2[0]-'0'+zw2[1]-'0';

    char a=zw1[2],b=zw2[2];

    if(cx1==cx2)
    {
        s[1]=1;
        if(pai1==pai2)
        {
            s[2]=1;
            if(a<='C' && b<='C' || a>='D' && b>='D')
                s[3]=1;


            if(a-b==1 || b-a==1)
                if(s[3]==1)
                    s[4]=1;
        }
    }
    for(int i=1;i<=4;i++)
        cout<<s[i];

    return 0;
}
