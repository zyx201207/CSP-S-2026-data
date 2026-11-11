#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100005],b[100005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=a[i];
        for(int j=1;j<=n;j++){
            if(a[i]=b[j])cout<<a[i]<<" ";
        }
    }
    return 0;
}
