#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans;
bool A,B;
long long m,a[500005],summ;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<"1";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=1e13;
    long long c=a[2]-a[1];
    if(a[1]==1){
        for(int i=1;i<=n;i++){
            if(a[i+1]-a[i]!=1){
                break;
            }
            if(i==n-1){
                A=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i+1]-a[i]!=c){
            break;
        }
        if(i==n-1){
            B=1;
        }
    }
    if(A){
        for(int i=1;i<=n;i++){
            if(i*(i-1)/2>m){
                cout<<i-1;
                return 0;
            }
        }
        if((m-n*(n-1)/2)%n==0){
            cout<<n;
            return 0;
        }
        else{
            cout<<n-1;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    if(B){
        if(a[1]<0){
            for(int i=1;i<=n;i++){
                if((a[i]-a[1])*i/2>m){
                    cout<<i-1;
                    return 0;
                }
            }
            if((m-(a[n]-a[1])*n/2)%n==0){
                cout<<n;
                return 0;
            }
            else{
                cout<<n-1;
                return 0;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if((a[i]+a[1])*i/2>m){
                    cout<<i-1;
                    return 0;
                }
            }
            if((m-(a[n]+a[1])*n/2)%n==0){
                cout<<n;
                return 0;
            }
            else{
                cout<<n-1;
                return 0;
            }
        }


    }
    l=1,r=1;
    while(r<n){
        while(summ>m){
            summ-=(a[r]-a[l]);
            l++;
        }
        while(summ<=m){
            r++;
            summ+=(a[r]-a[r-1])*(r-l);
        }
        ans=max(ans,r-l);
    }
    cout<<ans;
    return 0;
}
