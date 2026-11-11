#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t=0,b[500010];
        for(int j=i;j<=n;j++){
            for(int k=1;k<=t;k++){
                if(b[k]==a[j]){
                    t=k-1;
                    break;
                }
            }
            b[++t]=a[j];
        }
        for(int i=1;i<=t;i++){
            ans[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
