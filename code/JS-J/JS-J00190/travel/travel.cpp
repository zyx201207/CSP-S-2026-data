#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>s1;
    if(c!=c1)
        cout<<"0000";
    else{
        cout<<1;
        if(s[0]!=s1[0]||s[1]!=s1[1])
            cout<<"000";
        else{
            cout<<1;
            int tp=(s[2]<='C'),tp1=(s1[2]<='C');
            if(tp!=tp1)
                cout<<"00";
            else{
                cout<<1;
                char a=s[2],b=s1[2];
                if(a>b)
                    swap(a,b);
                if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))
                    cout<<1;
                else
                    cout<<0;
            }
        }
    }
    return 0;
}
