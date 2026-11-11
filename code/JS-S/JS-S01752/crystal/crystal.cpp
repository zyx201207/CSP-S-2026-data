#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],c[N];
int n,m,maxn;
bool allsame(){
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1])
            return 0;
    }
    return 1;
}
map<int,int> mp;
void dfs(int sum,int dep){
    if(dep==m||sum<=0){
        int last=1;
        for(int i=1;i<=n;i++) mp[a[i]]++;
        for(int i=-20;i<=20;i++){
            maxn=max(maxn,mp[i]);
            mp[i]=0;
        }
        return;
    }
    if(allsame()){
        cout<<n<<'\n';
        exit(0);
    }
    for(int i=1;i<n;i++){
        a[i]++;
        dfs(sum-1,dep+1);
        a[i]--;
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool fA=1,fB=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)
            fA=0;
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])
            fB=0;
    }
    if(fA){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i]-1;
            if(sum>m){
                cout<<i-1<<'\n';
                return 0;
            }
        }
        if(sum<=m)
            cout<<n<<'\n';
        return 0;
    }
    if(fB){
        int sum=0,t=a[2]-a[1];
        for(int i=2;i<=n;i++){
            sum+=t*(i-1);
            if(sum>m){
                cout<<i-1<<'\n';
                return 0;
            }
        }
        if(sum<=m)
            cout<<n<<'\n';
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(m,0);
    cout<<maxn<<'\n';
    return 0;
}
