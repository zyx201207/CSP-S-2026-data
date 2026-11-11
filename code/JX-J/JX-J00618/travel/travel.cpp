#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int f1=0,f2=0,f3=0,f4=0;
    if(c1[0]!=c2[0]||c1[1]!=c2[1])
    {
        cout<<f1<<f2<<f3<<f4;
    }else{
        f1=1;
        if(s1[0]!=s2[0]||s2[1]!=s1[1])
        {
            cout<<f1<<f2<<f3<<f4;
        }else{
            f2=1;
            if(int(s1[2])<int('D')&&int(s2[2])<int('D'))
            {
                f3=1;
                if(int(s1[2])-int(s2[2])==1&&s1[2]!='D')
                {
                    f4=1;
                    cout<<f1<<f2<<f3<<f4;
                }else if(int(s2[2])-int(s1[2])==1&&s2[2]!='D')
                {
                    f4=1;
                    cout<<f1<<f2<<f3<<f4;
                }else{
                    cout<<f1<<f2<<f3<<f4;
                }
            }else if(int(s1[2])>int('C')&&int(s2[2])>int('C'))
            {
                f3=1;
                if(int(s2[2])-int(s1[2])==1&&s2[2]!='D')
                {
                    f4=1;
                    cout<<f1<<f2<<f3<<f4;
                }else if(int(s1[2])-int(s2[2])==1&&s1[2]!='D')
                {
                    f4=1;
                    cout<<f1<<f2<<f3<<f4;
                }else{
                    cout<<f1<<f2<<f3<<f4;
                }
            }else{
                cout<<f1<<f2<<f3<<f4;
            }
        }
    }
return 0;
}
