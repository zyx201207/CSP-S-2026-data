#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +10;
long long a[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long num = 0;
    for(int i=n;i>=1;i--){
        long long ans = 0,w = 0;//ans mofa w zhongshu
        for(int j=i;j>=1;j--){
            ans += a[i] - a[j];
            if(ans <= m){
                //cout << ans << " ";
                w++;
            }
            if(ans >= m){
                //cout << w << " ";
                num = max(num,w);
                continue;
            }
        }
        //cout << '\n';
    }
    cout << num;
    return 0;
}
