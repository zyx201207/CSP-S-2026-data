#include <bits/stdc++.h>
using namespace std;
// #define int long long
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2;
    cin >>c1>>s1>>c2>>s2;
    if (c1[0]==c2[0]&&c1[1]==c2[1])
    {
        cout<< '1';
        if (s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<< '1';
            int t1=s1[2]-'A',t2=s2[2]-'A';
            int l1=(t1==3)||(t1 == 4)?1:2,l2=(t2==3)||(t2==4)?1:2;
            if (l1==l2&&abs(t1-t2)==1) cout<<"11";
            else if (l1==l2&&abs(t1-t2)!=1) cout<<"10";
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}