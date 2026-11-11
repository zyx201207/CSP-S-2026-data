#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n ,m;
    long long t1;
    cin >>n >>m;int c=0,jc=0;
    jc=n-m+1;
    for(long long i=jc;i>=1;i--){
        c+=i;
    }
    cin >>a[1];
    t1=a[1];
    for(long long i=2;i<=n;i++){
        cin >>a[i];
        t1&=a[i];
    }
    if(m==n){
        cout << t1;
        return 0;
    }
    if(m==n-1){
            long long q,y=0;
        for(long long i=2;i<=n;i++){
                q=a[1];
         for(long long j=2;j<=n;j++){
             if(i!=j){
                q=q&a[j];
             }

        }
        y=max(y,q);
        }
        for(int i=3;i<=n;i++){
            q=a[2];
            q=q&a[i];
        }
        y=max(y,q);
        cout <<y;
        return 0;
    }
    if (m==1){
        sort(a+1,a+1+n);
        cout <<a[n];
        return 0;
    }
    if(m==2){
    long long ans=0;
            for(long long i=1;i<n;i++){
                for(long long j=i+1;j<=n;j++){
                long long p1=a[i];
                long long p2=a[j];
                long long w=p1&p2;
                 ans=max(ans,w);
            }
            }
    cout << ans;
    }
return 0;
}
