#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a1>>b1>>a2>>b2;
    if(a1[0]=='0')
    {
        char xn1=a1[1];
        int x1=xn1-'0';
    }
    else
    {
        string xn1=a1;
        int x1=(xn1[0]-'0')*10+(xn1[1]-'0')*10;
    }
    if(a2[0]=='0')
    {
        char xn2=a2[1];
        int x2=xn2-'0';
    }
    else
    {
        string xn2=a2;
        int x2=(xn2[0]-'0')*10+(xn2[1]-'0')*10;
    }
    if(x1==x2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }



    string yn1=b1.substr(0,2);
    if(yn1[0]=='0')
    {
        char ym1=yn1[1];
        int y1=ym1-'0';
    }
    string yn2=b2.substr(0,2);
    if(yn2[0]=='0')
    {
        char ym2=yn2[1];
        int y2=ym2-'0';
    }
    if(y1==y2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }



    if((b1[2]=='E'&&b2[2]=='F')||(b1[2]=='F'&&b2[2]=='E'))
    {
        cout<<1;
    }
    else if((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))
    {

        cout<<1;
    }
    else
    {
        cout<<0;
    }




    if(((b1[2]=='E'&&b2[2]=='F')||(b1[2]=='F'&&b2[2]=='E'))||((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')))
    {
        if((b1[2]-'0'==b2[2]-'0'+1)||b1[2]-'0'==b2[2]-'0'-1)
        {

            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
