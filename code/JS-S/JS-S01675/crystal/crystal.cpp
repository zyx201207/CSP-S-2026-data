#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("crystal3.in","r",stdin);
    // freopen("crystal.out","w",stdout);
    long long n,m,cnt=1;
    cin >> n >> m;
    long long a[n+5],b[n+5],p[n+5]={};
    cin >> a[0];
    for (long long i=1;i<n;i++){
        cin >> a[i];
        b[i]=a[i]-a[i-1];
        p[i]=p[i-1]+b[i];
    }
    long long l=1,r=1,k=b[1];
    while (r<n){
        if (k<=m){
            r++;
            k+=b[r]*(r-l+1);
        }
        else{
            // cout << 'w';
            cnt=max(cnt,r-l+1);
            k=k+p[l-1]-p[r];
            l++;
        }
    }
    cnt=max(cnt,r-l+1);
    cout << cnt;
    return 0;
}
