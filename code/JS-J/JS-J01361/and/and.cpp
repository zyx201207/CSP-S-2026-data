#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005];
    long long mx=0,mn=INT_MAX;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if(m==1){
        cout<<mx<<"\n";
        return 0;
    }
    else if(m==2){
        long long mm=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
               long long k=(a[i]&a[j]);
               mm=max(mm,k);
            }
        }
        cout<<mm<<"\n";
    }
    else cout<<mn<<"\n";
    return 0;
}
