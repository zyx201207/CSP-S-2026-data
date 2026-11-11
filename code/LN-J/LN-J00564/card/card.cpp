#include<bits/stdc++.h>
using std::pair;
using std::make_pair;
using std::vector;
int n , m , a[500500] ;
pair<int,int> c[300300] ;
vector<int> have_id[300300] ;
int dp[500500] ;
bool is_last[500500] ;
int ans[300300] ;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        c[i].second=i;
    }
    for(int i=1;i<=n;i++){
        is_last[i]=false;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[a[i]].first=i;
        have_id[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        is_last[have_id[i].back()]=true;
    }
    sort(c+1,c+m+1);
    dp[0]=0;
    for(int i=1;i<=m;i++){
        dp[have_id[c[i].second].back()]=0;
        for(int j=(int)(have_id[c[i].second].size())-1;j>=0;j--){
            if(have_id[c[i].second][j]==1 || is_last[have_id[c[i].second][j]-1]==true){
                dp[have_id[c[i].second].back()]+=dp[have_id[c[i].second][j]-1]+1;
            }
            else dp[have_id[c[i].second].back()]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(is_last[i]==true){
            ans[a[i]]=dp[i];
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
