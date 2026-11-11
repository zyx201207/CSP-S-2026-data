#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],ans=0;
int an(int a,int b){
    return a&&b;
}
int fun(int a,int b){
    int s1=0,s2=0,k=1;
    while(a){
        s1+=(a%2)*k;
        k*=10;
        a/=2;
    }
    k=1;
    while(b){
        s2+=(b%2)*k;
        k*=10;
        b/=2;
    }
    int s=an(s1,s2);
    int p=0,r=0;
    k=1;
    while(s){
        r+=s%(k*10)/k*pow(2,p);
        p++;
        s-=s%(k*10)/k*k;
        k*=10;
    }
    return r;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                int t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==2){
        cout<<fun(a[n-1],a[n]);
        return 0;
    }
    for(int i=n-m+1;i<n;i++){
        ans+=fun(a[i],a[i+1]);
    }
    cout<<ans;
    return 0;
}
