#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e8+5;
int n,a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int flag=0,ans=0;;
    for(int i=1;i<=n;i++){
        int t;
        char c;
        cin>>t>>c;
        fill(a+flag,a+flag+t,c);
        flag+=t;
    }
    for(int i=0;i<flag/2;i++){
        if(a[i]!=a[flag-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
