#include<bits/stdc++.h>
using namespace std;
int a[500001],b[300001],c[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            b[a[j]]++;
            if(b[a[j]]>1){
                for(int k=1;k<=j;k++){
                    if(b[a[k]]>0)b[a[k]]--;
                }
                b[a[j]]++;
            }
        }
        for(int j=1;j<=n;j++)c[j]+=b[j];
    }
    for(int i=1;i<=m;i++)cout<<c[i]<<" ";
    return 0;
}
