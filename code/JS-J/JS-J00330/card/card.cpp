#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    long long a[n+1],x[m+1],y[m+1],ans[m+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)ans[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)x[j]=0,y[j]=0;
        for(int j=i;j<=n;j++){
            if(x[a[j]]==1){
                for(int k=y[a[j]];k<=j;k++)x[a[k]]=0,y[a[k]]=0;
            }
            x[a[j]]=1;
            y[a[j]]=j;
        }
        for(int i=1;i<=m;i++)ans[i]+=x[i];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
