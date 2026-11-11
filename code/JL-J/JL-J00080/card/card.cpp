#include<bits/stdc++.h>
using namespace std;
int n,m,k[500005],b[50005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int j=1;j<=n;j++){
        int a[30005];
        for(int i=j;i<=n;i++){
            a[b[i]]++;
        }
        for(int i=j;i<=n;i++){
            if(a[i]%2!=1) k[b[i]]+=2;
            else{
                k[b[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<k[i]/2<<" ";
    }
    return 0;
}
