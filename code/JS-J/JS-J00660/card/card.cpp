#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[505050];
vector<int>e[303030];
priority_queue<pair<int,int> > q;
set<int> s;
int ans[505050];
int res[303030];
int cnt[303030];
int vis[303030];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[a[i]].push_back(i);
        cnt[a[i]]++;
    }
    s.insert(a[n]);
    q.push({n,a[n]});
    q.push({0,0});
    ans[n]=n;
    int idx=lower_bound(e[a[n]].begin(),e[a[n]].end(),n)-e[a[n]].begin();
        while(e[a[n]][idx]>=(n-ans[n]+1)){
            vis[e[a[n]][idx]]=1;
            idx--;
        }
    for(int i=n-1;i>=1;i--){
        if(vis[i]) continue;
        while(q.top().first>=i){
            int id=q.top().second;
            int idx=lower_bound(e[id].begin(),e[id].end(),i)-e[id].begin();
            q.pop();
            q.push({e[id][idx-1],id});
            //cout<<q.top().first<<" "<<q.top().second<<'\n';
        }
        ans[i]=i-q.top().first;
        if(!s.count(a[i])){
            s.insert(a[i]);
            int id=a[i];
            int idx=lower_bound(e[id].begin(),e[id].end(),i)-e[id].begin();
            q.push({e[id][idx-1],id});
        }
        int idx=lower_bound(e[a[i]].begin(),e[a[i]].end(),i)-e[a[i]].begin();
        //cout<<idx<<" ";
        while(e[a[i]][idx]>=(i-ans[i]+1)){
            vis[e[a[i]][idx]]=1;
            idx--;
        }
    }
    for(int i=1;i<=n;i++){
        res[a[i]]+=ans[i];
        //cout<<ans[i]<<" ";
    }
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        //cout<<vis[i]<<" ";
    }
    //cout<<'\n';
    for(int i=1;i<=m;i++){
        cout<<res[i]<<" ";
    }
}
// g++ card.cpp -o card -std=c++14 -O2
// ./card