#include<bits/stdc++.h>
using namespace std;
const int N=20005;
long long dp_max[N],a[N],max_a,dp_min[N],min_a;
bool vis[N];
int main(){
    int n,m;
    cin>>n>>m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp_max[1]=max(a[i],dp_max[1]);
        dp_min[1]=min(a[i],dp_min[1]);
    }

    vis[1]=true;
    vis[n]=true;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==dp_max[i]||vis[j]) continue;
            dp_max[i]=max(dp_max[i-1]&a[j],dp_min[i-1]&dp_min[i-1]&a[j]);
            dp_min[i]=min(dp_max[i-1]&a[j],dp_min[i-1]&dp_min[i-1]&a[j]);
        }

    }
    cout<<dp_max[m];
    return 0;
}
