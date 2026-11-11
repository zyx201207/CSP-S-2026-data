#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,A=0,B=0,ans=0;
    cin>>n;
    long long m,t;
    long long a[n];
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i){
            A++;
        }
    }
    if(A==n){
            int c=m;
        for(long long i=1;i<=m;i++){
            if(i>c){
                break;
            }
            else{
                ans++;
                c-=i;
            }
        }
    ans++;
        if(ans<n){
            cout<<ans;
        }
        else{
            cout<<n;
        }
        return 0;
    }
    int d,e;
    d=a[2]-a[1];
    for(int i=1;i<n;i++){
        e=a[i+1]-a[i];
        if(e==d){
            B++;
        }
    }
    B++;
    if(B==n){
        int c=m;
        for(long long i=1;i<=m;i++){
            if(i*d>c){
                break;
            }
            else{
                ans++;
                c-=i*d;
            }
        }
    ans++;
        if(ans<n){
            cout<<ans;
        }
        else{
            cout<<n;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        if(a[j]>a[j+1]){
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
        }
        }
    }
    long long s;
    int p,k;
    for(int i=n;i>1;i--){
        s=m,p=0;
        for(int j=i-1;j>1;j--){
                k=a[i]-a[j];
            if(s>=k){
                p++;
                s-=k;
            }
            else{
                break;
            }
        }
        if(p>ans){
            ans=p;
        }
    }
    ans++;
    ans++;
    cout<<ans;
return 0;
}
