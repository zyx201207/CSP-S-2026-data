#include<bits/stdc++.h>
using namespace std;
const int kMaxN=2e6+5;
int C,T,dep[kMaxN],cnt[kMaxN];
long long n,d,x[kMaxN],ans;
vector<int> s[kMaxN];
set<long long> w;
void F(int sx){
    queue<int> q;
    q.push(sx);
    cnt[sx]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i:s[p]){
            if(i==sx) continue;
            if(!dep[i]){
                dep[i]=dep[p]+1;
                cnt[i]+=cnt[p];
                if(cnt[i]<=2) q.push(i);
            }else{
                if(dep[i]==dep[p]+1) cnt[i]++;
            }
        }
    }
}
void SA(){
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    long long dc=x[2]-x[1];
    long long bs=d/dc;
    if(bs==1||bs==0){
        cout<<0<<'\n';
        return;
    }
    for(long long i=1;i<=n;i++){
        if(i+bs*2-1<=n) ans++;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(cin>>C>>T;T;T--){
        cin>>n>>d;
        ans=0;
        w.clear();
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>1) w.insert(x[i]-x[i-1]);
            s[i].clear();
        }
        if(w.size()==1){
            SA();
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[i]-x[j])>d) continue;
                s[i].push_back(j);
                s[j].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++) dep[j]=cnt[j]=0;
            F(i);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}