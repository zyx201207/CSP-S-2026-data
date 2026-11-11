#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long mx=0;
    long long a[200005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,(a[i] & a[j]));
            }
        }

    }
    cout<<mx;
    return 0;
}
