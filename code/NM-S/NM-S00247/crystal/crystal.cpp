#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],z,d,c,cnt,maxn;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int long long i = 1;i<=n;i++){
        z=m,d=1,c=i,cnt=1;
        while(z>=0&&c<=n){
            if (z-(a[c+1]-a[c])*d>=0) z=z-(a[c+1]-a[c])*d,c++,d++,cnt++;
            else z=-1;

        }
        maxn=max(maxn,cnt);
    }
    cout << maxn;
    return 0;
}
