#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans[100005];
int b[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                int o=0;
            for(int l=1;l<=k;l++){
                if(a[j]==b[l]){
                    o=1;
                }
            }
            if(o==0){
                b[++k]=a[j];
            }
            else{
                    int p=0;
                for(int l=1;l<=k;l++){
                    if(a[j]==b[l]){
                        k=l;
                    }
                }
            }
        }
        for(int j=1;j<=k;j++){
            ans[b[j]]++;
            b[j]=0;
        }
        k=0;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
