#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],v[N],t[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]]++;
        t[a[i]]=i-1;
        if(i==n) t=a[i];
    }
    if(n==m){
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        return 0;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        if(t==2) cout<<v[1]<<' '<<n;
        else cout<<v[2]<<' '<<n;
        return 0;
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]+v[i]-1<<' ';
    }
    return 0;
}
