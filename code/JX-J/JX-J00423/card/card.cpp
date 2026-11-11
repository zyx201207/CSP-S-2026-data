#include<bits/stdc++.h>
using namespace std;
long long ans[300005];
int a[500005];
unordered_map<int,int>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        mp.clear();
        for(int j=i;j<=n;j++){
            if(mp[a[j]]==1){
                mp.clear();
            }
            mp[a[j]]=1;
        }
        for(auto it:mp){
            if(it.second==0){
                continue;
            }
            ans[it.first]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}
