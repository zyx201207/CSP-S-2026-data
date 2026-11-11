#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
bool cnt[500005];
int main(){
   // freopen("card.in","r",stdin);
   // freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        cnt[a[i]]=!cnt[a[i]];
    }for(int j=1;j<=n;j++){
        ans[j]+=cnt[j];
    }
    for(int i=1;i<m;i++){
        cnt[a[i]]=!cnt[a[i]];
        for(int j=1;j<=n;j++){
            ans[j]+=cnt[j];
        }
    };for(int j=1;j<=n;j++){
       if(ans[j]) cout<<ans[j]<<' ';
    }
    return 0;
}

