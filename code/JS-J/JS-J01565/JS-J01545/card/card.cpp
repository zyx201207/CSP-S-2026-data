#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],cnt[N],flag[N];
vector<int> G[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        for(int k=1;k<=m;++k){
            G[k].clear();
            flag[k]=0;
        }
        for(int j=i;j<=n;++j){
           if(flag[a[j]]==1){
                for(int k=G[a[j]][0];k<j;++k){
                    G[a[k]].clear();
                    flag[a[k]]=0;
                }
                G[a[j]].push_back(j);
                flag[a[j]]=1;
           }else{
              flag[a[j]]=1;
              G[a[j]].push_back(j);
           }
       }
       for(int k=1;k<=m;++k){
            if(!G[k].empty()){
                cnt[k]++;
            }
        }
    }
    for(int i=1;i<=m;++i){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
