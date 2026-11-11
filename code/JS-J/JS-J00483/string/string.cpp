#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int y,z=0,n,b;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b>>c;
        for(int j=1;j<=b;j++)
        {
            s+=c;
        }
    }
    y=s.size();
    for(int i=0;i<y/2;i++)
    {
        if(s[i]!=s[y-1-i])
        {
            z++;
        }

    }
    cout<<z;
    return 0;
}
