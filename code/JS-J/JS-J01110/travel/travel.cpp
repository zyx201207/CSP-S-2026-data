#include<bits/stdc++.h>
using namespace std;
#define intt long long
const int MAXN=200005;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1)
    {
        cout<<1;
        if(s2[0]==t2[0]&&s2[1]==t2[1])
        {
            cout<<1;
            char a=s2[2]-'A',b=t2[2]-'A';
            if(a==5) a=4;
            if(b==5) b=4;
            if((a>=0&&a<=2&&b>=0&&b<=2)||(a>=3&&a<=4&&b>=3&&b<=4))
            {
                cout<<1;
                if(a-b==1||b-a==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
