#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2) cout<<1;
    else    cout<<0;
    int a1=0,b1=0;
    char p1,p2;
    for (int i=0;i<3;i++)
    {
        if (i==0||i==1)
        {
            a1=a1*10+s1[i]-'0';
            b1=b1*10+s2[i]-'0';
        }
        if (i==2)
        {
            p1=s1[i];
            p2=s2[i];
        }
    }
    if (a1==b1&&c1==c2) cout<<1;
    else    cout<<0;
    if (a1==b1&&c1==c2&&(abs(p1-p2)==2||abs(p1-p2)==1)&&p1!='D'&&p1!='F'&&p2!='D'&&p2!='F')   cout<<1;
    else if (a1==b1&&c1==c2&&(p1=='D'&&p2=='F')||(p1=='F'&&p2=='D'))    cout<<1;
    else cout<<0;
    if (a1==b1&&c1==c2&&abs(p1-p2)==1&&p1!='C'&&p1!='D'&&p2!='C'&&p2!='D')   cout<<1;
    else    if(a1==b1&&c1==c2&&(p1=='D'&&p2=='F')||(p1=='F'&&p2=='D'))  cout<<1;
    else    cout<<0;
    return 0;
}
