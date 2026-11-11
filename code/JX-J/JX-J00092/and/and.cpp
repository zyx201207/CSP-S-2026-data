#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
long long sum,maxv;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum&=a[i];
        maxv=max(maxv,a[i]);
    }
    if(m==n){cout << sum; return 0;}
    if(m==1){cout << maxv; return 0;}
    if(m==2){
        maxv=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                maxv=max(maxv,a[i]&a[j]);
            }
        }
        cout << maxv;
        return 0;
    }
    sort(a+1,a+n+1);
    cout << (a[n] & a[n-1] & a[n-2]);
}
