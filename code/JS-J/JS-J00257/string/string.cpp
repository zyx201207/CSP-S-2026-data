#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long n, ia, ib, ba, bb, mi, t=0;
    cin>>n;
    long long s[n];
    char ch[n];
    for (int i=0;i<n;i++) {cin>>s[i];cin>>ch[i];}
    ia=0;ib=n-1;ba=0;bb=s[n-1];
    while (ia<ib)
    {
        mi=min(s[ia]-ba, bb);
        if (ch[ia]!=ch[ib])
        {
            ba+=mi;bb-=mi;
            if (ba>=s[ia]) {ba=0;ia++;}
            if (bb<=0) {ib--;bb=s[ib];}
            t+=mi;
        }
        else
        {
            ba+=mi;bb-=mi;
            if (ba>=s[ia]) {ba=0;ia++;}
            if (bb<=0) {ib--;bb=s[ib];}
        }
    }
    cout<<t;
    return 0;
}
