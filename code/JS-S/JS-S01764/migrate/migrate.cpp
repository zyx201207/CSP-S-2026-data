#include<bits/stdc++.h>
///#define int long long
using namespace std;
int n,d,a[2000005],cnt[5005],dis[5005],lst[2000005];
int nxt(int i){
    int p;
    if(a[n]-a[i]<=d)    p=n;
    else    p=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    return p;
}
struct node{
    int t,d;
    bool operator<(const node&p)const{
        return d>p.d;
    }
    bool operator>(const node&p)const{
        return d<p.d;
    }
};
int bfs(int now){
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    priority_queue<node>q;
    q.push({now,0});
    dis[now]=0;
    int res=0;
    while(!q.empty()){
        now=q.top().t;
        q.pop();
        for(int i=now+1;i<=lst[now];i++){
            if(dis[i]>dis[now]+1){
                dis[i]=dis[now]+1;
                q.push({i,dis[i]});
            }
            if(dis[i]==dis[now]+1){
                cnt[i]++;
            }
        }
    }
    /*
    while(!q.empty()){
        now=q.front().t;
        int ds=q.front().d;
        q.pop();
        for(int i=now+1;i<=lst[now];i++){
            if(!dis[i]){
                dis[i]=ds;
                cnt[i]++;
                q.push({i,ds+1});
            }
            else if(dis[i]==ds){
                cnt[i]++;
                q.push({i,ds+1});
            }
        }
    }
    */
    for(int i=1;i<=n;i++)   if(cnt[i]==2)   res++;
    return res;
}
void f(){
    cin >> n >> d;
    for(int i=1;i<=n;i++)   cin >> a[i];
    for(int i=1;i<=n;i++)   lst[i]=nxt(i);
    int res=0;
    for(int i=1;i<=n;i++){
        res+=bfs(i);
    }
    cout << res << '\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int TT,T;
    cin >> TT >> T;
    while(T--)  f();
    return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

