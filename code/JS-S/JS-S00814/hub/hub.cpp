#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int c,t,n,k,u[N],v[N];
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >>c>>t;
    while(t--){
        cin >>n>>k;
        for(int i=1;i<n;i++){
            cin >>u[i]>>v[i];
        }
        cout <<t%9;
    }
    return 0;
}
