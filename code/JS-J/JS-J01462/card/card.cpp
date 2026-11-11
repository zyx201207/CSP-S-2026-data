#include <bits/stdc++.h>
using namespace std;
long long n,m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<long long>a(n);
    vector<bool>vis((m+1),false);
    vector<long long>dis((m+1),0);
    vector<long long>sum((m+1),0);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    deque<int> cd;
    for(int i=n-1;i>=0;i++) {
        if(vis[a[i]]==false) {
            cd.push_front(a[i]);
            vis[a[i]]=true;
            dis[a[i]]=cd.size()-1;
            /*
            for(auto s : cd){
                sum[s]++;
            }
            */
        }else{
            for(int i=0;i<(cd.size()-dis[a[i]]-1);i++) {
                vis[cd.front()]=false;
                dis[cd.front()]=0;
                cd.pop_front();
                /*
                for(auto s : cd){
                    sum[s]++;
                }
                */
            }
        }
    }
    for(int i=1;i<=m;i++) {
        cout<<sum[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
