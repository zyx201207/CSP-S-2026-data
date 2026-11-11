#include <bits/stdc++.h>
using namespace std;

long long andness(long long a,long long b){
    if(a==b){
        return a;
    }
    long long n=a,m=b,as=0,bs=0;
    while (n){
        n/=2;
        as+=1;
    }
    while (m){
        m/=2;
        bs+=1;
    }
    long long s=max(as,bs);
    long long a2[s],b2[s],res[s];
    for (long long i=0;i<s;i++){
        a2[i]=0;
        b2[i]=0;
    }
    for (long long i=0;i<as;i++){
        a2[s-1-i]=a%2;
        a/=2;
    }
    for (long long i=0;i<bs;i++){
        b2[s-1-i]=b%2;
        b/=2;
    }
    for (long long i=0;i<s;i++){
        if(a2[i]==1&&b2[i]==1){
            res[i]=1;
        }
        else{
            res[i]=0;
        }
    }
    long long solve=0;
    for (int i=s-1;i>=0;i--){
        solve+=res[i]*pow(2,s-1-i);
    }
    return solve;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans,h=0;
    cin>>n>>m;
    long long a[n];
    for (long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==n){
        ans=a[0];
        for (int i=0;i<n;i++){
            ans=andness(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    else if(m==1){
        ans=a[0];
        for (int i=0;i<n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==2){
        ans=-99999;
        for (long long i=0;i<n;i++){
            for (long long j=i+1;j<n;j++){
                long long f=ans;
                ans=max(f,andness(a[i],a[j]));
            }
        }
        cout<<ans;
    }
    else if(m==3){
        ans=-99999;
        for (long long i=0;i<n;i++){
            for (long long j=i+1;j<n;j++){
                for (long long k=j+1;k<n;k++){
                    long long f=ans;
                    ans=max(f,andness(andness(a[i],a[j]),a[k]));
                }
            }
        }
        cout<<ans;
    }
    else if(m==4){
        ans=-99999;
        for (long long i=0;i<n;i++){
            for (long long j=i+1;j<n;j++){
                for (long long k=j+1;k<n;k++){
                    for (long long l=k+1;l<n;l++){
                        long long f=ans;
                        ans=max(f,andness(andness(andness(a[i],a[j]),a[k]),a[l]));
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
