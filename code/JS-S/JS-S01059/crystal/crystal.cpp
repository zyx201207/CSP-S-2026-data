#include<bits/stdc++.h>
using namespace std;

int n,cnt;
long long m,a[500005];
long long s[500005];

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }

    for(int i=1;i<=n;i++){
        int maxi = 0;
        for(int j=i;j<=n;j++){
            if((j - i + 1) * a[j] <= s[j] - s[i-1] + m) maxi = j - i + 1;
            else break;
        }
        if(maxi > cnt) cnt = maxi;
    }

    cout << cnt;

    return 0;
}
