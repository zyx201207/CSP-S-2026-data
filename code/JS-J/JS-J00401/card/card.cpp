#include "bits/stdc++.h"
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],cnt[N],ans[N],sum1[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        memset(sum1,0,sizeof(sum1));
        for(int j=n;j>=i;j--){
             sum1[a[j]]=1;
            if(cnt[a[j]]>1)
                break;
        }
        //memset(sum,0,sizeof(sum));
        for(int j=i;j<=n;j++){
            sum1[a[j]]=1;
            if(cnt[a[j]]>1)
                break;
        }
        for(int i=1;i<=m;i++)
            ans[i]+=sum1[i];
       // for(int i=1;i<=m;i++)
       //     cout<<ans[i]<<" ";
       // cout<<endl;
        cnt[a[i]]--;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
