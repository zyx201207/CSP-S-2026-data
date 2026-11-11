#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],b[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;++i)
        cin>>a[i];
    sort(a + 1,a + 1 + n);
    int l = 0,num = 0;
    for(int i = 1;i <= n;++i){
        b[i] = b[i - 1] + a[i];
        while(l <= n && b[i] - b[l] + m < (i - l) * a[i])
            ++l;
        num = max(num,i - l);
    }
    cout<<num;
    return 0;
}