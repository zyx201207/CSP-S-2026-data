#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==m){
        long long x=a[0];
        for(int i=1;i<n;i++){
            x=x & a[i];
        }
        cout<<x;
        return 0;
    }
    int maxx=-1;
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[i] & a[j])>=maxx)maxx=(a[i] & a[j]);
        }
    }
    cout<<maxx;
    return 0;
}
