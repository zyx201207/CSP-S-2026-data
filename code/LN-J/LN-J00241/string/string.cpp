#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,sum;
vector<char> v;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    v.push_back(0);
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        cnt+=a;
        while(a--) v.push_back(c);
    }
    for(int i=1;i<=(cnt+1)/2;i++){
        if(v[i]!=v[cnt+1-i]) sum++;
    }
    cout<<sum;
    return 0;
}
