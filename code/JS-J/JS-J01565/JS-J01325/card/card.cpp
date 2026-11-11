#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        t=i;
        bool f[300005]={0};
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                f[a[j]]=1;
            }
            else if(f[a[j]]==1){
                t=j;
            }
        }
        for(int k=t;k<=n;k++){
            b[a[k]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
