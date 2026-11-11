#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef zzr
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000\n";
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"000\n";
        return 0;
    }
    cout<<1;
    if((s1[2]<='C')!=(s2[2]<='C'))
    {
        cout<<"00\n";
        return 0;
    }
    cout<<1;
    cout<<(abs(s1[2]-s2[2])==1);
}
//  0  1  2  3  4  5  6  7
// 27 28 29 30 31 32 33  8
// 26 47 48 49 50 51 34  9
// 25 46 59 60 61 52 35 10
// 24 45 58 63d                                            62 53 36 11
// 23 44 57 56 55 54 37 12
// 22 43 42 41 40 39 38 13
// 21 20 19 18 17 16 15 14
