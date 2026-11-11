#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b,c,d;
    char e,f;
    a=(c1[0]-'0')*10+(c1[1]-'0');
    b=(s1[0]-'0')*10+(s1[1]-'0');
    c=(c2[0]-'0')*10+(c2[1]-'0');
    d=(s2[0]-'0')*10+(s2[1]-'0');
    e=s1[2];
    f=s2[2];
    if(a==c)
        if(b==d)
            if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='A'&&f=='C')||(e=='C'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='B')||(e=='D'&&f=='F')||(e=='F'&&f=='D'))
                if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='B')||(e=='D'&&f=='F')||(e=='F'&&f=='D'))
                    cout<<"1111"<<endl;
                else
                    cout<<"1110"<<endl;
            else
                cout<<"1100"<<endl;
        else
            cout<<"1000"<<endl;
    else
        cout<<"0000"<<endl;
    return 0;
}