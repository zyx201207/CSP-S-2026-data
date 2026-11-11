#include<bits/stdc++.h>
using namespace std;
long long a[500100];
long long c[500100];

map<long long,long long>p;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        p[a[i]]++;
    }
    if(m==0){
        long long max=0;
        for(long long i=0;i<=1e5;i++){
            if(p[i]>max){
                max=p[i];
            }
        }
        cout<<max;
        return 0;
    }
    sort(a+0,a+n);
    long long x=0;//无-1,A 1,b 2
    long long now=0;
    long long k=a[1]-a[0];
    for(long long i=2;i<n;i++){
        now=a[i]-a[i-1];
        if(now!=k){
            x=-1;
            break;
        }
    }
    if(x!=-1){
        if(k==1){
            x=1;
        }
        else{
            x=2;
        }
    }
    if(x==-1){
        c[0]=0;
        for(long long i=1;i<n;i++){
            long long sum=0;
            for(long long j=i-1;j>=0;j--){
                sum+=(a[i]-a[j]);
            }
            c[i]=sum;
        }
        if(m>c[n-1]){
            cout<<n;
            return 0;
        }
        if(m<c[n-1]){
            long long g=0;
            for(long long i=0;i<n;i++){
                if(m<c[i]){
                    g=i;
                    break;
                }
                if(m==c[i]){
                    g=i+1;
                    break;
                }
            }
            cout<<g;
            return 0;
        }
    }
    if(x==2||x==1){
        c[0]=0;
        for(long long i=1;i<n;i++){
            c[i]=c[i-1]+(a[i]-a[0]);
        }
        if(m>=c[n-1]){
            cout<<n;
            return 0;
        }
        if(m<c[n-1]){
            long long g=0;
            for(long long i=0;i<n;i++){
                if(m<c[i]){
                    g=i;
                    break;
                }
                if(m==c[i]){
                    g=i+1;
                    break;
                }
            }
            cout<<g;
            return 0;
        }
    }
return 0;
}
