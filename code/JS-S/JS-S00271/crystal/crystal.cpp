#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m;
int rl[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>rl[i];
    }
    sort(rl+1,rl+n+1,greater<int>());
    int ans=0;
    int cnt=1,cntpre=1,nowm=m,nowans=1;
    while(cnt<n){
        if(nowm>=(rl[cntpre]-rl[cnt+1])){
            nowm-=(rl[cntpre]-rl[cnt+1]);
            cnt++;
            nowans++;
            //cout<<nowans;
        }else if(cnt!=cntpre){
            ans=max(ans,nowans);
            nowm+=(rl[cntpre]-rl[cntpre+1])*(cnt-cntpre);
            nowans--;
            cntpre++;
        }else{
            nowm=m;
            nowans=0;
            cnt++;
            cntpre=cnt;
        }
    }
    ans=max(ans,nowans);
    cout<<ans<<endl;
    return 0;
}
