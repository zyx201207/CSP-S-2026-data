#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long mx;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
    mx=max(a[i]&a[i+1],mx);
    }
    if(m==2){
        cout<<mx;
    }else{
    for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
        mx=max(mx&a[j],mx);
    }
    }
    cout<<mx;
    }
}
