#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[50005],ans[30005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int f[30005]={0};
        int b[50005]={0};
        int k=0;
        for(int j=i;j<=n;j++){
            k++;
            if(f[a[j]]==0){
                b[k]=a[j];
                f[a[j]]=k;
            }else{
                for(int g=f[a[j]];g<j;g++){
                    f[a[g]]=0;
                    k--;
                }
                f[a[j]]=k;
                b[k]=a[j];
            }
        }
        for(int j=1;j<=k;j++){
//            cout<<b[j]<<" ";
            ans[b[j]]++;
        }
//        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
