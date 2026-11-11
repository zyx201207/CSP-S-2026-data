#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;cin>>n>>m;
    long long maxn=INT_MIN;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if (m==n){
        long long p=a[1];
        for (int i = 2;i<=n;i++)p=(p&a[i]);
        cout << p;
    }
    else if (m==1)cout << maxn;
    else if (m==2){
        long long k=INT_MIN;
        for (int i = 1;i<=n;i++){
            for (int j = i+1;j<=n;j++){
                if (a[i] && a[j])k=max(k,(long long)(a[i]&a[j]));
            }
        }
        cout << k;
    }
    return 0;
}
