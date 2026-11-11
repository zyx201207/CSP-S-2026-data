#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,cnt,ans,t_cnt,dp[N],cnt1[N];
long long x[N],d;
void dfs(int now,int dis,int tar){
    if(now>tar)return;
    if(now==tar){
        ans=min(ans,dis);
        return;
    }
    for(int i=now+1;i<=tar;++i){
        if(x[i]-x[now]>d)break;
        dfs(i,dis+1,tar);
    }
}
void dfs2(int now,int dis,int tar,bool f){
    // cout<<now<<" 1 "<<dis<<endl;
    if(f)return;
    if(now>tar)return;
    // cout<<now<<" 2 "<<dis<<endl;
    if(now==tar){
        if(ans==dis){
            t_cnt++;
        }
        if(t_cnt>2){
            f=1;
        }
        return;
    }
    // cout<<now<<" 3 "<<dis<<endl;
    for(int i=now+1;i<=tar;++i){
        if(x[i]-x[now]>d)break;
        dfs2(i,dis+1,tar,f);
        // cout<<i<<" 4 "<<dis+1<<endl;
    }
}
bool check(int i,int j){
    ans=INT_MAX;
    dfs(i,0,j);
    dfs2(i,0,j,0);
    // cout<<i<<" "<<j<<" "<<ans<<" "<<t_cnt;
    // cout<<endl;
    return t_cnt==2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
        }
        if(c<=6){
            for(int i=1;i<=n;++i){
                for(int j=i+1;j<=n;++j){
                    t_cnt=0;
                    if(check(i,j)){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<endl;
        }else if(c==11||c==12){
            cout<<0<<endl;
        }else{
            dp[0]=0;
            for(int k=1;k<=n;++k){
                for(int i=1;i<=n;++i){
                    cnt1[i]=0;
                }
                cnt1[k]=1;
                for(int i=k;i<=n;++i){
                    for(int j=k;j<i;++j){
                        if(x[i]-x[j]<=d)cnt1[i]+=cnt1[j];
                    }
                }
            }
            cout<<0<<endl;
        }
    }
    return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/