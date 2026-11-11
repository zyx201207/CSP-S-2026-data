#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<char> v;
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1,x;i<=n;i++){
        char ch;
        cin>>x>>ch;
        for (int j=1;j<=x;j++)
            v.push_back(ch);
    }
    int len=v.size();
    for (int i=0;i<=len/2;i++){
        if (v[i]!=v[len-1-i])
            ans++;
    }
    cout<<ans;
    return 0;
}
