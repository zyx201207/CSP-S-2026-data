#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[300005],p[500005],q[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=i;j<=n;j++){
            q[p[j]]++;
            if(q[p[j]]>1){
                for(int z=i;z<j;z++){
                    if(z==p[j]){
                        k=z;
                        break;
                    }
                }
                for(;k<=j;k++)q[p[k]]=0;
                q[p[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(q[j]==1){
                ans[j]++;
                q[j]=0;
            }
        }
    }
    for(int j=1;j<=m;j++)cout<<ans[j]<<' ';
    return 0;
}
