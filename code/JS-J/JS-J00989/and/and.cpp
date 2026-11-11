#include <bits/stdc++.h>
using namespace std;
int n, m, r;
vector<int> a;

int f(int n){
    int cnt = 0;
    int q = 2;
    while (n != 0){
        cnt+=n%2*q;
        n/=2;
        q*=2;
    }
    return cnt;
}
int f2(int n){
    int cnt = 0;
    while (n != 0){
        cnt+=n%2;
        n/=2;
    }
    return cnt;
}
bool cmp(int a, int b){
    if (n >= 100){
        return (f2(a)>f2(b));
    }
    return (f(a)>f(b));
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for (int i = 0, x;i < n;i++){
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), cmp);

    r = a[0];
    for (int i = 1;i < m;i++){
        r = r & a[i];
    }
    cout<<r;
    return 0;
}