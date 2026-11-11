#include<bits/stdc++.h>
using namespace std;
int n,m,ans[400000];
int a[510000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            ans[a[i]]++;
        }
        ans[a[n]]=n;
        cout<<ans[1]<<' '<<ans[2];
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i+1]!=a[i]){
                cout<<i<<' ';
            }
        }
    }
    return 0;
}
