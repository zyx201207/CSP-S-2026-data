#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2;
    char s1[4],s2[4];
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        long long a1=((s1[0]-'0')*10)+(s1[1]-'0');
        long long a2=((s2[0]-'0')*10)+(s2[1]-'0');
        if(a1==a2)
        {
            cout<<"1";
            char b1=s1[2];
            char b2=s2[2];
            if(b1=='A'&&(b2!='D'&&b2!='F') || b1!='F'&&(b1!='D'&&b2=='A')
               ||b1=='B'&&(b2!='D'&&b2!='F') || b1!='F'&&(b1!='D'&&b2=='B')
               ||b1=='C'&&(b2!='D'&&b2!='F') || b1!='F'&&(b1!='D'&&b2=='C')
               ||b1=='D'&&b2=='F'||b1=='F'&&b2=='D')
            {
                cout<<"1";
                if(b1=='A'&&b2=='B'||b1=='B'&&b2=='A' || b1=='B'&&b2=='C'||b1=='C'&&b2=='B' || b1=='D'&&b2=='F'||b1=='F'&&b2=='D')
                {
                    cout<<"1"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"0"<<endl;
                    return 0;
                }

            }

            else
            {
                cout<<"00"<<endl;
                return 0;
            }


        }
        else
        {
            cout<<"000"<<endl;
            return 0;
        }

    }
    else
    {
        cout<<"0000"<<endl;
        return 0;
    }

    return 0;
}

