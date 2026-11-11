#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500025],C;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<i<<" ";
    }
    sort(a+1,a+n+1);
    long long d=1e12;
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i])d=min(a[i+1]-a[i],d);
    }
    if(d==1e12){
        cout<<n;
        return 0;
    }
    int s=d,C=1;
    while(m>=s){
        m-=s;
        s+=d;
        C++;
    }
    cout<<C<<endl;
    return 0;
}
