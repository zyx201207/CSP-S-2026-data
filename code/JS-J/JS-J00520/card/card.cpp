#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],k,c[510],cnt,d[510];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int v=1;v<=n;v++){
        for(int j=1;j<=k;j++)b[j]=0;
        for(int j=1;j<=n;j++)c[j]=0;
        k=0;
        for(int i=v;i<=n;i++){
            if(c[a[i]]==1){
                for(int j=1;j<=k;j++)b[j]=0;
                for(int j=1;j<=n;j++)c[j]=0;
                b[1]=a[i];
                c[a[i]]=1;
                k=1;
            }
            else{
                c[a[i]]=1;
                b[++k]=a[i];
            }
        }
        for(int i=1;i<=k;i++){
            d[b[i]]++;
            b[i]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<d[i]<<" ";
    return 0;
}
