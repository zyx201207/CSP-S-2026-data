/*
sol1 -> 40pts done n^2
sol2 -> 10pts
sol3 -> 10pts
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol1(){
    int n;long long d;cin>>n>>d;
    vector<int>x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    vector<vector<int>>g(n+1);
    long long tot=0;
    for(int _=0;_<n;_++){
        queue<int>q;
        vector<char>vis(n+1,0),vis2(n+1,0);
        vector<long long>cnt(n,1e18),f(n,0);
        cnt[_]=0;
        q.push(_);
        vis[_]=1;
        //is there a chance that we can know which should we choose next?
        while(q.size()){
            int u=q.front();q.pop();
            //cout<<u<<": ";
            for(int i=u+1;i<n;i++){
                if(x[u]+d<x[i])break;
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                    cnt[i]=min(cnt[i],cnt[u]+1);
                }
                //cout<<i<<" ";
            }
            //cout<<'\n';
        }
        q.push(_);
        vis2[_]=1;
        while(q.size()){
            int u=q.front();q.pop();
            //cout<<u<<": ";
            for(int i=u+1;i<n;i++){
                if(x[u]+d<x[i])break;
                //cout<<i<<"."<<(bool)vis2[i]<<" ";
                if(!vis2[i]){
                    q.push(i);
                    vis2[i]=1;
                }else{
                    if(cnt[i]==cnt[u]+1){
                        f[i]++;
                        if(f[i]>1)tot--;
                        else tot++;
                    }
                }
            }
            //cout<<'\n';
        }
    }
    cout<<tot<<'\n';
}
/*
0 4
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        sol1();
    }
}