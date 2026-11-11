#include <bits/stdc++.h>
using namespace std;
int a[500010],k[300010],kz[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            k[a[j]]++;
            }for(int j=1;j<=m;j++){
                kz[j]+=k[j]%2;
                k[j]=0;
            }
        }
    for(int i=1;i<=m;i++){
        cout<<kz[i]<<" ";
    }
    return 0;
}

