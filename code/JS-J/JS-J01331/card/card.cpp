#include <bits/stdc++.h>
using namespace std;
int a[500005],jl[300005],wz[300005],sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(jl,0,sizeof jl);
        memset(wz,0,sizeof wz);
        for(int j=i;j<=n;j++){
            if(jl[a[j]]==0){
                jl[a[j]]++;
                wz[a[j]]=j;
            }
            else{
                for(int k=wz[a[j]];k<j;k++){
                    jl[a[k]]=0;
                }
                jl[a[j]]++;
                wz[a[j]]=j;
            }
        }
        for(int j=1;j<=m;i++){
            if(jl[i])
                sum[i]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<sum[i]<<' ';
    return 0;
}
