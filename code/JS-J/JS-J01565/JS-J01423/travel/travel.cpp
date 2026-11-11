#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
int c1,c2,h1,h2,l1,l2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        h1=h1*10+s1[i]-'0';
        h2=h2*10+s2[i]-'0';
    }
    l1=s1[2]-'A'+1,l2=s2[2]-'A'+1;
    if(c1!=c2) cout<<"0000";
    else{
        cout<<1;
        if(h1!=h2) cout<<"000";
        else{
            cout<<1;
            if(l1/4!=l2/4) cout<<"00";
            else{
                cout<<1;
                if(l1>l2) swap(l1,l2);
                if(l1==1&&l2==2) cout<<1;
                else if(l1==2&&l2==3) cout<<1;
                else if(l1==4&&l2==6) cout<<1;
                else cout<<0;
            }
        }
    }
    return 0;
}
