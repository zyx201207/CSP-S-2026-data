//CSP-S 2026 RP++!
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::ios;
using std::vector;

#define int long long 

const int N=2e6+5,NN=5e3+5;

vector<int> vec[N];

int n,a[N],ans,has,res,d,c,T,dp[NN][NN],st[N],h,t;

void dfs(int now,int mb,int sum){
    if(now==mb){
        if(sum==res)has++;
        if(sum<res)res=sum,has=1;
        return ;
    }
    for(int i=now+1;i<=mb;i++){
        if(a[i]-a[now]<=d)dfs(i,mb,sum+1);
        else break;
    }
}

bool check(int u,int v){
    res=INT_MAX,has=0;
    dfs(u,v,0);
    return has==2;
}

void temp_solve_a(){
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(check(i,j))ans++;
    cout<<ans<<'\n';
}

void temp_solve_b(){
    for(int i=1;i<=n;i++){
        int sum=1;
        st[h=t=1]=i;
        for(int j=i;j<=n;j++){
            if(j==i){
                dp[i][j]=1;
                continue;
            }
            while(a[j]-a[st[h]]>d&&h<=t)
                sum-=dp[i][st[h]],h++;
            dp[i][j]=sum,sum+=dp[i][j],st[++t]=j;
            if(dp[i][j]==2)
                ans++;
        }
    }
    for(int i=1;i<=n;i++,cout<<'\n')
        for(int j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
    cout<<ans<<'\n';
}

void temp_solve(){
    cin>>n>>d,ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(c==1||c==2)temp_solve_a();
    else temp_solve_b();
}

void solve(){
    cin>>c>>T;
    while(T--)
        temp_solve();
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
