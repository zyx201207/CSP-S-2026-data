#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check(long long x[]){
    int a=x[0];
    for(int i=1;i<n;i++){
        if(a!=x[i]) return 0;
    }
    return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long maxx=0;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m=1){
        cout<<maxx;
        return 0;
    }
    if(check(a)){
        cout<<maxx;
        return 0;
    }
    if(m==n){
        int ans=a[0];
        for(int i=0;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }int i=1;
    while(pow(2,i)<2*1e5){
        if(n==pow(2,i)){
            long long s=pow(2,i);
            if(i<m){
                for(int j=m;j>i;j--){
                    s-=int(pow(2,j));
                }
            }
            cout<<s;
            return 0;
        }
    }
    if(m==2){
        long long maxxx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxxx=max(maxxx,a[i]&a[j]);
            }
        }
        cout<<maxxx;
        return 0;
    }
    return 0;
}
