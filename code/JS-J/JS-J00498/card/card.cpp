#include<bits/stdc++.h>
using namespace std;
int a[1000005],k[1000005],f[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        long long l=0;
        for(int j=i;j<=n;j++){
            for(int d=1;d<=l;d++){
                if(a[j]==k[d]){
                    l=d-1;
                    break;
                }
            }
            l++;
            k[l]=a[j];
        }
        for(int j=1;j<=l;j++)f[k[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<f[i]<<' ';
    return 0;
}
