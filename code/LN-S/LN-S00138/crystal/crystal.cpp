#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],p[500005],cost[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m == 0){
        int cnt = 1;
        int ans = 0;
        for(int i = 2;i<=n;i++){
            if(a[i] == a[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans,cnt);
        }
        cout<<ans;
        return 0;
    }
    for(int i = 1;i<=n;i++) p[i] = a[i]-a[i-1];
    int point;
    cost[1] = 0;
    for(point = 2;point<=n;point++){
        cost[point] = (point-1)*p[point]+cost[point-1];
        if(cost[point]>m){
            break;
        }
    }
    cout<<point-1;
    return 0;
}
