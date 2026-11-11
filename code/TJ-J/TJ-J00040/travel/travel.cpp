 #include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1="",c1="",s2="",c2="";
    cin>>s1>>c1>>s2>>c2;
    if(s1==s2)
    {
        cout<<"1";
        if(c1.at(0)==c2.at(0)&&c1.at(1)==c2.at(1))
        {
            cout<<"1";
            char a=c1.at(2),b=c2.at(2);
            if(a<='C'&&b<='C'||a>='D'&&b>='D')
            {
                cout<<"1";
                if(abs(a-b)==1)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}

