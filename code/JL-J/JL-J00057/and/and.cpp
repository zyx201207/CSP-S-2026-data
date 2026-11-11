#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],_2=0,_3=0;
    unsigned long long t[200005]={1};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==2) _2++;
        if(a[i]==3) _3++;
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n){
        long long sum=1;
        for(int i=1;i<=n;i++){
            sum=(sum&a[i]);
        }
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        for(int j=1;j<=n;j++){
            long long sum=1;
            for(int i=1;i<=n;i++){
                if(i==j) continue;
                sum=(sum&a[i]);
            }
            t[j]=sum;
        }
        long long tip=0;
        for(int i=1;i<=n;i++){
            if(tip<t[i]) tip=i;
        }
        cout<<t[tip];
        return 0;
    }
    if(m==2){
        long long sum=1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>sum) sum=a[i]&a[j];
            }
        }
        cout<<sum;
        return 0;
    }
    sort(a+1,a+n+1);
    if((_2+_3)<m) cout<<0;
    else{
        cout<<2;
    }
    return 0;
}
