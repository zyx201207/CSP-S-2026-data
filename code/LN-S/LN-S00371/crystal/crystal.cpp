#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db cerr<<"fff"<<'\n';
/*
max_element()
accumulate()
priority_queue
*/

long long n,m;
vector<long long> a;
int f(int x) {
    int sum = 0;
    for (int i = 0; i < x-1; i++) {
        sum += a[i];
    }
    for (int i = 0,j = x-1; j < n; i++,j++) {
        sum+=a[j];
        if (x*a[j]-sum <= m)return 1;
        sum-=a[i];
    }
    return 0;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int l=1,r=n-1;
    while(l<r) {
        int mid = ((l+r)/2*2==(l+r))?(l+r)/2:(l+r)/2+1;
        if (f(mid))l = mid;
        else r = mid-1;
    }
    cout << l;
    return 0;
}
