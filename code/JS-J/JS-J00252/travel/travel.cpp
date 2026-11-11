#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,t1,s2,t2;
    cin>>s1>>t1>>s2>>t2;
    if (s1==s2)
    {
        cout<<1;
        if (t1.substr(0,2)==t2.substr(0,2))
        {
            cout<<1;
            if (('A'<=t1[2]&&t1[2]<='C'&&'A'<=t1[2]&&t1[2]<='C')||('D'<=t1[2]&&t1[2]<='E'&&'D'<=t1[2]&&t1[2]<='E'))
            {
                cout<<1;
                if (abs(int(t1[2]-t2[2]))==1)
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"0000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
