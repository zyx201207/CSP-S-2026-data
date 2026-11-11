#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string a1,a2;
    a1+=a[0];a1+=a[1];
    a2+=c[0];a2+=c[1];
    int a11=stoi(a1);
    int a22=stoi(a2);
    if(a11!=a22)
    {
        cout<<"0000";
        return 0;
    }


    string b1,b2;
    b1+=b[0];b1+=b[1];
    b2+=d[0];b2+=d[1];
    int b11=stoi(b1);
    int b22=stoi(b2);
    if(b11!=b22)
    {
        cout<<"1000";//false
        return 0;
    }

    int c1,c2;
    c1=int(b[2]);
    c2=int(d[2]);
    if((b[2]<='C' && d[2]<='C')||(b[2]>='D' && d[2]>='D'))
    {
        if(abs(c1-c2)!=1)
            cout<<"1110";
        else
            cout<<"1111";
    }
    else
    {
        cout<<"1100";
    }
    /*
    if(char i='A',i<='E';i++)
    {
        if(c1==i && c2==char(i+1))
    }
    */
    return 0;
}
//four numbers:
//1.if(chexiang==)
//2.if(tong yi pai)
//3.if(tong yi ce)
//4.if(xiang ling)
//then you can cout<<1111;)
