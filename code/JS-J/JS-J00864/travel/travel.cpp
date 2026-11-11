#include<bits/stdc++.h>
using namespace std;
/*void fun1()
{
    cin>>c1>>s1>>c2>>s2;
    cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
            {
                cout<<"1";
                if(s1[2]<='C')
                {
                    if(s1[2]=='B'||s2[2]=='B') cout<<"1";
                    else cout<<"0";
                }
                if(s1[2]>'C')
                {
                    cout<<"1";
                }
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return;
}*/
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
            {
                cout<<"1";
                if(s1[2]<='C')
                {
                    if(s1[2]=='B'||s2[2]=='B') cout<<"1";
                    else cout<<"0";
                }
                if(s1[2]>'C')
                {
                    cout<<"1";
                }
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    //fun1();
    return 0;
}
