#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int walk[N];
struct Node{
    int time;
    int stat;
}sub[505];
bool cmp(Node a,Node b){
    return a.stat<b.stat;
}
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>walk[i];
    }
    int cnt = 0,tmp = 1;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        cnt += k;
        for(int j=1;j<=k;j++){
            cin>>sub[tmp].stat>>sub[tmp].time;
            tmp ++;
        }
    }
    sort(sub+1,sub+cnt+1,cmp);
    while(q--){
        int x,y,ans = 0;
        cin>>x>>y;
        int l,r;
        for(int i=1;i<=cnt;i++){
            if(sub[i].stat == x){
                l = i;
                break;
            }
        }
        for(int i=1;i<=cnt;i++){
            if(sub[i].stat == y){
                r = i;
                break;
            }
        }
        for(int i=l;i<=r;i++){
            ans += sub[i].time;
        }
        ans+=(walk[x]+walk[y]);
        cout<<ans<<endl;
    }

    return 0;
}
