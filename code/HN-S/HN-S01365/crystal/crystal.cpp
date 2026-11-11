#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ans=0,zhong,b,t;
int a[N];
int main(){
    freopen("crystal.in","r",stdin);
    reopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
for(int i=1;i<=n;i++){
    t=i+1;
    while(t!=n+1&&a[i]>a[t]){
    b=a[i];
    a[i]=a[t];
    a[t]=b;
    t++;
    }

}
    zhong=a[n/2+1];
    for(int j=1;j<=n;j++){
        if(a[j]>zhong){
            continue;
        }
        while(a[j]!=zhong){
            a[j]++;
        }
    }
    for(int u=1;u<=n;u++){
        if(a[u]==zhong){
        ans++;
        }
    }
    cout<<ans;
    return 0;
}
