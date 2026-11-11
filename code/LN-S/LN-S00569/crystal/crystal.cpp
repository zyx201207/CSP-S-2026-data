#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long m;
    cin >> n >> m;

    long long a[n+5];

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++) cout << a[i] << ' ';

    long long maxx = -1;
    for(int i=1;i<=n;i++){
            long long k = a[i];
        for(int j=i+1;j<=n;j++){
            long long l = j-i;
            if(a[j] * l - k <= m){
                maxx = max(maxx,l+1);
                k = k + a[j];
            }
            else{
                break;
            }
        }
    }
    cout << maxx;
    return 0;
}
