#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],sum=1,maax=-100;
long long p(long long a[500050],long long n){
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    return a[500050];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    p(a,n);
    long long b=m;
    for(long long k=0;k<n-1;k++){
        for(long long i=1+k;i<n;i++){
            if(a[1+k]<a[2+k] && b>=(a[2+k]-a[1+k])){
                b=b-(a[2+k]-a[1+k]);
                a[1+k]=a[2+k];
                long long a1=1;
                for(long long j=3+k;j<=n;j++){
                    if(a[j]==a[2+k]){
                        a1++;
                    }else{
                        break;
                    }
                }
                sum+=a1;
            }
            else if(a[i]<a[i+1] && b>=(a[i+1]-a[i])){
                long long c=0,d=0;
                for(long long j=1+k;j<=n;j++){
                    if(a[j]==a[i]){
                        c+=(a[i+1]-a[i]);
                        d=j;
                    }else{
                        break;
                    }
                }
                if(b>=c){
                    for(long long j=1+k;j<=d;j++){
                        a[j]=a[i+1];
                    }
                    b-=c;
                    long long b1=1;
                    for(long long j=i+2;j<=n;j++){
                        if(a[j]==a[i+1]){
                            b1++;
                        }else{
                            break;
                        }
                    }
                    sum+=b1;
                }
            }
        }
        if(sum>maax){
            maax=sum;
        }
        sum=1;
    }
    cout<<maax;
    return 0;
}
