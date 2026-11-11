#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int t[N][2], num[N][2], n, m, a[N], idx, ans;
void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int tmp=(1&(x>>i));
        if(t[p][tmp]==0) t[p][tmp]=++idx;
        num[p][tmp]++;p=t[p][tmp];
    }
}
void bfs(){
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while(!q.empty()){
        queue<pair<int, int>> tmp;
        pair<int, int> x=q.front();q.pop();
        if(x.second>30) return ;
        int b=0;b+=num[x.first][1];
        while(!q.empty()&&q.front().second==x.second){
            pair<int, int> y=q.front();q.pop();tmp.emplace(y);
            b+=num[y.first][1];
        }
        if(b>=m){
            ans+=(1<<(30-x.second));
            if(t[x.first][1]!=0) q.emplace(t[x.first][1], x.second+1);
            while(!tmp.empty()){
                pair<int, int> y=tmp.front();tmp.pop();
                if(t[y.first][1]!=0) q.emplace(t[y.first][1], y.second+1);
            }
        }else{
            if(t[x.first][1]!=0) q.emplace(t[x.first][1], x.second+1);
            if(t[x.first][0]!=0) q.emplace(t[x.first][0], x.second+1);
            while(!tmp.empty()){
                pair<int, int> y=tmp.front();tmp.pop();
                if(t[y.first][1]!=0) q.emplace(t[y.first][1], y.second+1);
                if(t[y.first][0]!=0) q.emplace(t[y.first][0], y.second+1);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) insert(a[i]);
    bfs();
    cout << ans;
    return 0;
}
