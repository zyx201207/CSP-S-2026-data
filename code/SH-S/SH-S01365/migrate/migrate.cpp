#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,x[2000010];
void solvedb(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    ll gc=x[2]-x[1];
    if(gc*2>d){
        cout<<0<<endl;
        return;
    }
    ll walklen=d/gc;
    cout<<max(n-2*walklen+1,0ll)<<endl;
}
ll dp[2000010],cnt[2000010];
void solve_brute(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    ll ans=0;
    for(int i=1;i<n;i++){
        dp[i]=0;cnt[i]=1;
        for(int j=i+1;j<=n;j++) dp[j]=1e18;
        for(int j=i+1;j<=n;j++) cnt[j]=0;
        for(int j=i+1;j<=n;j++){//本次计算的
            for(int k=i;k<j;k++){//枚举上一步
                if(x[j]-x[k]>d) continue;
                if(dp[k]+1<dp[j]){
                    dp[j]=dp[k]+1;
                    cnt[j]=cnt[k];
                }else if(dp[k]+1==dp[j]){
                    cnt[j]+=cnt[j];
                }
            }
        }
        for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
    }
    cout<<ans<<endl;
}
ll s[2000010];
void solve_advanced(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    ll ans=0;
    for(int i=1;i<n;i++){
        dp[i]=0;cnt[i]=1;s[i]=1;s[i-1]=0;
        for(int j=i+1;j<=n;j++) dp[j]=1e18;
        for(int j=i+1;j<=n;j++) cnt[j]=0;
        for(int j=i+1;j<=n;j++) s[j]=0;
        ll l=i;ll r=i;
        for(int j=i+1;j<=n;j++){//本次计算的
            while(x[j]-x[l]>d) l++;
            if(l==j) break;
            dp[j]=dp[l]+1;
            while(dp[r]<=dp[l]&&r<j) r++;
            cnt[j]=s[r-1]-s[l-1];
            s[j]=s[j-1]+cnt[j];
        }
        for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        if(c==11||c==12) solvedb();
        else if(c>=1&&c<=6) solve_brute();
        else solve_advanced();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
恰好有两条是什么意思？

手模了一下，发现两条路线最多只能有一个岛屿不一样。

否则就可以在不同的线路之间跳跃了。

把存在x a y与x b y的数字对看作原始二元对
发现两个路线可以通过原始二元对扩充出来

筛选原始二元对：
需要x->a->y可达x->b->y可达，a<b，x->y不可达，b-a=1
x->b+1不可达，a-1->y不可达

延长条件：
对于p<x,p->x有唯一的最短路线，最后一步的岛屿不能直接进入x+1

可以在左边dp一次数一下p，右边dp一次数一下

对于一个a,b，只有最边缘的两个可能延长，其他的不可能延长。

等差数列：没有可以延长的

随心飞：有三个随心飞岛屿就没招了
有两个随心飞岛屿……
有一个随心飞岛屿……

哎呀，开始打暴力吧

三次方应该还是可以的，钦定起点计算终点最短路方案数量


枚举上一步这一维应该可以省掉，可以做一个cnt前缀和状物
*/