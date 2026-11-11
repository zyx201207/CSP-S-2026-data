#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+1);
    vector<long long> pre(n+1,0);
    long long i;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(i=1;i<=n;i++){
        pre[i] = pre[i-1]&a[i];
    }
    long long left = 0;
    long long total=0;
    for (i=1;i+m<=n;i++){
        if (pre[i+m]&pre[i-1]>total){
            total = pre[i+m]&pre[i-1];
        }
    }
    long long temp=a[n];
    for (long long i=n-1;i>n-m;i--){
        temp = temp &a[i];
    }
    long long tt = max(temp,total);
    if (tt==0){
        cout << a[n];
    } else {
        cout << tt;
    }
    return 0;
};
