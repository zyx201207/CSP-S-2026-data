#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,cnt;
vector<int>v[2000005];
int dis[2000005];
bitset<35>b;
int dfs(int fa,int x,int dep){
    dis[x]=dep;
    int mxx=x;
    for(auto i:v[x]){
        if(fa==i)continue;
        int tmp=dfs(x,i,dep+1);
        if(dis[mxx]<dis[tmp]);
            mxx=tmp;
    }
    return mxx;
}
int get_g(){
    int ans=dfs(0,1,0);
    memset(dis,0,sizeof dis);
    return dfs(0,ans,0);
}
int ddfs(int fa,int x,int last){
    int ans=last;
    for(auto i:v[x]){
        last=b[i-1]?0:last+1;
        if(b[i]==1&&b[x]==0)cnt++;
        ans=max(ans,ddfs(x,i,last));
    }
    return (cnt<2)?ans:1e18;
}
void solve(){
    int ans=1e18;
    for(int i=1;i<(1<<n);i++){
        b=i;
        if(b.size()!=k);
            continue;
        for(int i=1;i<=n;i++){
            if(b[i]==1){
                ans=min(ans,ddfs(0,i,0));break;
            }
        }
    }
    cout<<ans<<endl;

}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(n<=30){
            solve();
            break;
        }
        int root=get_g();
        priority_queue<int>q;
        bool fl=1;
        for(auto i:v[root]){
            if(fl){
                fl=0;
                q.push((dis[i]+1)/2);
            }
            else q.push(dis[i]);
        }
        if(q.size()==1){
            cout<<(q.top()-k+1+1)/2<<endl;
        }
        while(k){
            int tmp=q.top();
            q.pop();
            if(tmp==q.top())q.push(tmp-1),k--;
            else if(tmp-k<q.top()){
                    k-=tmp-q.top();
                q.push(q.top());
            }
            else {
                q.push(tmp);
                break;
            }
        }
        cout<<q.top()-k<<endl;
    }
}
