#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int tmp=i;
        while(tmp<=n){
            tmp=b[a[tmp]];
            ans[a[tmp]]++;
            tmp++;
        }
    }
    for(int i=1;i<=m;i++)
      cout<<ans[i]<<" ";
    return 0;
}
