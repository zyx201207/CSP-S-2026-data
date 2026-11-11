#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f[500005];
int ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s=0;
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        int s=0;
        for(int j=i;j<=n;j++){
            s++;
            f[s]=a[j];
            int tot=0;
            for(int k=1;k<s;k++){
                if(f[k]==a[j]){
                    f[k]=-1;
                    tot=1;
                }else{
                    if(tot==1)f[k]=-1;
                }
            }
        }
        for(int j=1;j<=s;j++)ans[f[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
