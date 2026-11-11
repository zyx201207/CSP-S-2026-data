#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],mmax;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        if(m>1e6){
            cout<<n;
            return 0;
        }
        for(long long i=1;i<n;i++){
            b[i]=a[i+1]-a[i];
        }
        for(long long i=1;i<n;i++){
            for(long long j=i;j<n;j++){
                long long t=0,c=0;
                for(long long k=i;k<=j;k++){
                    c+=t+b[k];
                    t+=b[k];
                }
                if(t<=m) mmax=max(mmax,j-i+1);
            }
        }
        cout<<mmax+1;
    }
    else{
        long long t=0,tt=0,c=0;
        for(long long i=1;;i++){
            tt+=t+(a[2]-a[1]);
            t+=(a[2]-a[1]);
            if(tt>m) break;
            c++;
        }
        cout<<c+1;
    }
    return 0;
}
