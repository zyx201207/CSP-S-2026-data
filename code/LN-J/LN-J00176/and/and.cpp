#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],mmax,c=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        c*=i;
        if(c>1e6) break;
    }
    for(long long k=1;k<=c;k++){
        long long t=a[1];
        for(long long i=2;i<=m;i++){
            t=t&a[i];
        }
        mmax=max(t,mmax);
        next_permutation(a+1,a+n+1);
    }
    cout<<mmax;
    return 0;
}
