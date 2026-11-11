#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long b[300010];
int f[300010];
int ax[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ax[i]=a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            ax[i]=a[i];
        }
        memset(f,0,sizeof(f));
        for(int i=k;i<=n;i++){
            if(f[ax[i]]==0){
                f[ax[i]]=i;
            }
            else{
                for(int j=f[ax[i]];j<=i-1;j++){
                    f[ax[j]]=0;
                    ax[j]=0;
                }
                f[ax[i]]=i;
            }
        }
        for(int i=k;i<=n;i++){
            if(ax[i]!=0){
                b[ax[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
