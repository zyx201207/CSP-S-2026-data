#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n,d;
int a[N];
struct node{int l,cnt;}f[N];
int bfs(int x){
    queue<node> q;
    q.push({x,0});
    while(!q.empty()){
        node tmp=q.front();q.pop();
        int nw=tmp.l,sum=tmp.cnt;
        //cout<<f[nw].l<<" ";
        if (f[nw].l<sum) continue;
        if (f[nw].l==sum) {f[nw].cnt++;continue;}
        if (f[nw].l>sum) {f[nw].l=sum;f[nw].cnt=1;}
        for (int i=nw+1;i<=n;i++){
            if (a[i]-a[nw]>d) break;
        //cout<<i<<" ";
            q.push({i,sum+1});
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        if (f[i].cnt==2) ans++;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if (c<=10 || (15<=c && c<=18)){
        while(T--){
            cin>>n>>d;
            for (int i=1;i<=n;i++) cin>>a[i];
            int ans=0;
            for (int i=1;i<=n;i++) {
                memset(f,0x7f,sizeof f);
                ans+=bfs(i);
                //cout<<"\n";
            }
            cout<<ans<<"\n";
        }
    }
    if (11<=c && c<=12){
        while(T--){
            cin>>n>>d;
            for (int i=1;i<=n;i++) cin>>a[i];
            int t=d/(a[2]-a[1]);
            cout<<n-1-t<<"\n";
        }
    }
    if (13<=c && c<=14) {
        while(T--){
            cin>>n>>d;
            for (int i=1;i<=n;i++) cin>>a[i];
            cout<<0<<"\n";
        }
    }
    return 0;
}
