#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long a[500005];
    long long m;
    cin >> m;
    for (int i = 0;i<=n-1;i++){
        cin >> a[i];
    }
    int s = 1;
    for (long long j = 1;j<=m;j++){
        for (long long t = 0;t<=n-2;t++){
            if (a[t]>a[t+1])a[t+1]++;
            else if(a[t]<a[t+1])a[t]++;
        }
    }
    for (long long r = 0;r<=n-2;r++){
        if (a[r] == a[r+1])s++;
    }
    cout << s;
    return 0;
}
