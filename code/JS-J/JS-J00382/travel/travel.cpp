#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string tr_a,st_a,tr_b,st_b;
    cin >> tr_a >> st_a >> tr_b >> st_b;
    int ta=(tr_a[0]-'0')*10+(tr_a[1]-'0');
    int tb=(tr_b[0]-'0')*10+(tr_b[1]-'0');
    int pa=(st_a[0]-'0')*10+(st_a[1]-'0');
    int pb=(st_b[0]-'0')*10+(st_b[1]-'0');
    int sa=(st_a[2]=='F'?5:st_a[2]-64);
    int sb=(st_b[2]=='F'?5:st_b[2]-64);
    bool f1,f2,f3,f4;
    f1=(ta==tb);
    f2=(f1&&pa==pb);
    f3=(f2&&((sa<=3&&sb<=3)||(sa>3&&sb>3)));
    f4=(f3&&abs(sb-sa)==1);
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
