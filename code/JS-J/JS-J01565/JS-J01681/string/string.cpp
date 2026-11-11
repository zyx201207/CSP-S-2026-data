#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
    int cnt;
    char c;
}a[200010];
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].cnt >> a[i].c;
    }
    int i = 1,j = n,ans = 0;
    while(i < j){
        if(i == j) break;
        int cntl = a[i].cnt,cntr = a[j].cnt;
        int cnt = min(cntl,cntr);
        if(a[i].c != a[j].c){
            ans += cnt;
        }
        a[i].cnt -= cnt;
        a[j].cnt -= cnt;
        if(a[i].cnt == 0) i++;
        if(a[j].cnt == 0) j--;
    }
    cout << ans << '\n';
    return 0;
}