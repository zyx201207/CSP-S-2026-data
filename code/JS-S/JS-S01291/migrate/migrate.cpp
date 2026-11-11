#include<bits/stdc++.h>
using namespace std;
using ll=long long;
queue<int> q;
vector<int> a(2000009);
vector<int> dis(2000009);
vector<vector<int>> adj;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        dis[0]=0;
        a[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        q.push(0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=x+1;i<=n;i++){
                if(a[i]-a[x]<=d){
                    adj[i].push_back(x);
                    q.push(i);
                    dis[i]++;
                }
                else{
                    break;
                }
            }

        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==2){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}