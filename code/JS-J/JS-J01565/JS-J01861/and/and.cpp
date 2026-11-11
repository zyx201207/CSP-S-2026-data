#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int n,m,a[N],dp[N],cnt,ans,res,mx,cc,tt;

void dfs(int depth){
    if(cnt>m)return ;
    if(n-depth+1+cnt<m)return ;
    if(res<ans&&res!=0)return ;
    if(depth>n){
        if(cnt!=m)return ;
        ans=max(ans,res);
        return ;
    }
    for(int i=0;i<=1;i++){
        if(i==1){
            int t=res;
            if(cnt==0)res=a[depth];
            else res=res&a[depth];
            cnt++;
            dfs(depth+1);
            res=t;
            cnt--;
        }
        else dfs(depth+1);
    }
    return ;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        if(i==1)cc=a[i];
        else cc=cc&a[i];
    }
    tt=a[1];
    for(int i=2;i<=m;i++){
        tt=tt&a[i];
    }
    if(n<=30){
        dfs(1);
        cout<<ans;
    }
    else if(m==1){
        cout<<mx;
    }
    else if(m==n){
        cout<<cc;
    }
    else if(m==2&&n<=6000){
        int rs=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                rs=max(rs,a[i]&a[j]);
            }
        }
        cout<<rs;
    }
    else if(1ll*n*m<=2000000000ll){
        for(int i=1;i<=n;i++){
            for(int j=m;j>=2;j--){
                if(j>i)continue;
                dp[j]=max(dp[j],a[i]&dp[j-1]);
            }
        dp[1]=max(dp[1],a[i]);
        }
        cout<<max(dp[m],tt);
    }
    else{
        cout<<tt;
    }
    return 0;
}
