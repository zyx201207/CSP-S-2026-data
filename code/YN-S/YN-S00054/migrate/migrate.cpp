#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int rd(){
    char c=getchar_unlocked();
    int res=0,f=1;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*f;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=rd(),t=rd();
    if(c<=10){
    while(t--){
        int n=rd(),d=rd();
        vector<int> w(n+1);
        vector<vector<int>> a(n+1);
        vector<int> rudu(n+1);
        for(int i=1;i<=n;i++){
            w[i]=rd();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(w[j]-w[i]<=d)
                    a[i].push_back(j),rudu[j]++;
                else break;
            }
        }
        queue<int> q;
        int ans=0;
        for(int i=1;i<=n;i++){
            vector<int> nrd=rudu;
            vector<int> dist(n+1,1e18),cnt(n+1,0);
            dist[i]=0;cnt[i]=1;
            q.push(i);
            while(!q.empty()){
                int now=q.front();q.pop();
                for(const int &j:a[now]){
                    if(dist[j]==1e18){
                        dist[j]=dist[now]+1;
                        cnt[j]=cnt[now];
                    }
                    else if(dist[now]+1==dist[j]){
                        cnt[j]++;
                    }
                    nrd[j]--;
                    if(!nrd[j]) q.push(j);
                }
            }
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
            for(const int &j:a[i]){
                rudu[j]--;
            }
        }
        cout<<ans<<'\n';
    }
    }
    else{
        while(t--)
            cout<<0<<'\n';
    }
    return 0;
}
