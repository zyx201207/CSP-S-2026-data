#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bool f[200005]={};
        for(int j=1;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[k]==a[j]&&!f[k]){
                        for(int x=k;x<j;x++)f[x]=1;
                    }
                }
        }
        for(int j=i;j<=n;j++){
            if(!f[j])ans[a[j]]++;
//            if(!f[j])cout<<a[j]<<" ";
        }
//       cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
