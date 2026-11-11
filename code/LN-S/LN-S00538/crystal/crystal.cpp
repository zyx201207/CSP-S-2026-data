#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000009],h[1000009][1000009],k=1,u[10000009],o=1,f[1000009];
long long xyz(long long p){
    long long t=0;
    while(o<=k){
    u[o]=0;
    for(long long e=o;e<=k;e++){
        if(t<=m)
        if(h[p][e]-a[p]>0){
                u[o]=u[o]+h[p][e];
        }
        else{
            if(h[p][e]-a[p]<0){
                    t+=a[p]-h[p][e];
                    u[o]=u[o]+h[p][e];
            }
            else{
                t+=0;
                u[o]+=h[p][e];
            }
        }
    }
    o++;
    }
    sort(u,u+1);
    long long c=u[o];
    return c;
}
int main(){
    //freopen(crystal.in,"r",stdin);
    //freopen(crystal.out,"w",stdout);
    cin >> n>> m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
            h[i][k]=0;
        for(long long j=m;j>=-m;j--){
            if(m%2==0){
                if(a[i]+j==a[i+j]){
                    h[i][k]=a[i+j];
                    k++;
                }
            }
            else{
                if(a[i]+j==a[i+j]){
                    h[i][k]=a[i+j];
                    k++;
                }
            }
        }
        f[i]=xyz(i);
        k=0;
    }
    sort(f,f+1);
    cout<<f[n];
return 0;
}
