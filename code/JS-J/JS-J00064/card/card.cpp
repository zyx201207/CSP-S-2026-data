#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+5;
int a[N],ans[M],cnt[M],wei[M];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt[a[j]]++;
            if(cnt[a[j]]==1)wei[a[j]]=j;
            if(cnt[a[j]]>1){
               for(int c=wei[a[j]];c<=j;c++){
                   cnt[a[c]]--;
               }
               cnt[a[j]]=1;
               wei[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(cnt[j]>0)ans[j]++;
            cnt[j]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
