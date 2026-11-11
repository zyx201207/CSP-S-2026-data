#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,cb,sa,sb;
    cin>>ca>>sa>>cb>>sb;
    if(ca==cb)
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0<<0<<"\n";
        return 0;
    }
    string a;
    a+=sa[0];
    a+=sa[1];
    string b;
    b+=sb[0];
    b+=sb[1];
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0<<"\n";
        return 0;
    }
    char x=sa[2],y=sb[2];
    //cout<<x<<" "<<y<<"\n";
    //cout<<('C'>='D')<<"\n";
    if((x<='C'&&y<='C')||(x>='D'&&y>='D'))
    {
        //cout<<(x>='D'||y>='D')<<"\n";
        cout<<1;
    }
    else
    {
        cout<<0<<0<<"\n";
        return 0;
    }
    if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||
    (x=='D'&&y=='F')||(x=='F'&&y=='D'))
    {
        cout<<1<<"\n";
    }
    else
    {
        cout<<0<<"\n";
    }
    return 0;
}
