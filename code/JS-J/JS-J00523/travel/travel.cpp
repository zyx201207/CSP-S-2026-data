#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
string ss1,ss2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>ss1>>c2>>ss2;//分别表示小 R 的车票上的车厢号、座位号,以及小 X 的车票上的车厢号、座位号。
    s1=(ss1[0]-'0')*10+ss1[1]-'0';
    s2=(ss2[0]-'0')*10+ss2[1]-'0';
    char cs1=ss1[2],cs2=ss2[2];
    //cout<<c1<<s1<<cs1<<" "<<c2<<s2<<cs2;
    if(c1==c2)
    {
        cout<<1;
        if(s1==s2)
        {
            cout<<1;
            if((cs1=='F'&&cs2=='D')||(cs1=='D'&&cs2=='F')||(cs1=='A'&&cs2=='B')||(cs1=='A'&&cs2=='C')||(cs1=='B'&&cs2=='A')||(cs1=='B'&&cs2=='C')||(cs1=='C'&&cs2=='A')||(cs1=='C'&&cs2=='B'))
            {
                cout<<1;
                if((cs1=='F'&&cs2=='D')||(cs1=='D'&&cs2=='F')||(cs1=='A'&&cs2=='B')|(cs1=='B'&&cs2=='A')||(cs1=='B'&&cs2=='C')||(cs1=='C'&&cs2=='B'))
                    cout<<1;
                else
                    cout<<0;
            }
            else
            {
                cout<<"00";
            }
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    cout<<"\n";
    return 0;
}