#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n, a[N], b[N], idx1=1, idx2=1, cnt, x;
char c[N], s[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
    for(int i=1, j=n;i<=n&&j>=1;i++, j--) b[j]=a[i], s[j]=c[i];
    while(idx1<=n&&idx2<=n){
        if(c[idx1]==s[idx2]){
            if(a[idx1]<b[idx2]) b[idx2]-=a[idx1], idx1++;
            else if(a[idx1]>b[idx2]) a[idx1]-=b[idx2], idx2++;
            else idx1++, idx2++;
        }else{
            if(a[idx1]<b[idx2]) cnt+=a[idx1], b[idx2]-=a[idx1], idx1++;
            else if(a[idx1]>b[idx2]) cnt+=b[idx2], a[idx1]-=b[idx2], idx2++;
            else cnt+=a[idx1], idx1++, idx2++;
        }
    }
    cout << cnt/2;
    return 0;
}
