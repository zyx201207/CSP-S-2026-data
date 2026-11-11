#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int CCFILOVEYOU,t,n;
ll d,a[N];
namespace sub1{
    int dp[5005],cnt[5005],lst[5005];
    ll solve(){
        for(int i=1,j=1;i<=n;i++){
            while(j<i && a[i]-a[j]>d)j++;
            lst[i]=j;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            dp[i]=0,cnt[i]=1;
            for(int j=i+1;j<=n;j++){
                int l=max(i,lst[j]);
                if(l==j)break;
                dp[j]=dp[l]+1;
                if(l+1<j && dp[l+1]==dp[l]){
                    if(l+2<j && dp[l+2]==dp[l])cnt[j]=3;
                    else cnt[j]=min(3,cnt[l]+cnt[l+1]);
                }
                else cnt[j]=cnt[l];
                if(cnt[j]==2)ans++;
            }
        }
        return ans;
    }
}
namespace sub2{
    ll solve(){
        if(n==1)return 0;
        ll k=d/(a[2]-a[1]);
        if(k<=1 || k*2-1>=n)return 0;
        return n-(k*2-1);
    }
}
namespace sub3{
    ll solve(){
        int p=1;
        while(a[n]-a[p]>d)p++;
        if(n==1 || p==1)return 0;
        int l1=p-1;
        while(l1 && p+2<=n && a[p+2]-a[l1]<=d)l1--;
        int l2=l1;
        while(l2 && a[p+1]-a[l2]<=d)l2--;
        int r1=p+1;
        while(r1<=n && p-2>0 && a[r1]-a[p-2]<=d)r1++;
        int r2=r1;
        while(r2<=n && a[r2]-a[p-1]<=d)r2++;
        return 1ll*(l1-l2)*(n-r2+1)+1ll*(r2-r1)*l2;
    }
}
namespace sub4{
    int lst[N],nxt[N],len1[N],len2[N],f[21][N],g[21][N],sum1[21][N],sum2[21][N],sum3[21][N];
    bool is1[21][N],is2[21][N],is3[21][N];
    long long ans;
    ll solve(){
        ans=0;
        for(int i=1,j=1;i<=n;i++){
            while(j<i && a[i]-a[j]>d)j++;
            lst[i]=j;
            //cerr<<i<<' '<<lst[i]<<endl;
        }
        for(int i=n,j=n;i;i--){
            while(j>i && a[j]-a[i]>d)j--;
            nxt[i]=j;
            f[0][i]=j;
            //cerr<<i<<' '<<nxt[i]<<endl;
        }
        for(int i=1,j=1,k=1;i<=n;i++){
            if(j<=i)j=i+1;
            if(k<=i)k=i+1;
            while(j<=nxt[i] && lst[j]<i-1)j++;
            while(k<=nxt[i] && lst[k]<i)k++;
            len1[i]=nxt[i]-k+1,len2[i]=k-j;
            is1[0][i]=int(len1[i]>1),is3[0][i]=int(len1[i]>0);
            sum1[0][i]=len2[i],sum3[0][i]=len1[i];
            //cerr<<i<<' '<<len1[i]<<' '<<len2[i]<<endl;
        }
        for(int i=1;i<21;i++)for(int j=1;j<=n;j++)
            f[i][j]=f[i-1][f[i-1][j]],
            sum1[i][j]=sum1[i-1][j]+sum1[i-1][f[i-1][j]],sum3[i][j]=sum3[i-1][j]+sum3[i-1][f[i-1][j]],
            is1[i][j]=is1[i-1][j]&is1[i-1][f[i-1][j]],is3[i][j]=is3[i-1][j]&is3[i-1][f[i-1][j]];
        for(int i=1;i<=n;i++){
            sum2[0][i]=0;
            if(i<n){
                int x=nxt[i]==i?i+1:nxt[i];
                for(int j=20;~j;j--)if(is1[j][x])sum2[0][i]+=sum1[j][x],x=f[j][x];
                g[0][i]=x,is2[0][i]=int(len1[i]>0);
                if(len1[i]==1 && len1[nxt[i]]>1)sum2[0][i]+=len2[x]-len2[nxt[i]];
                //cerr<<i<<' '<<g[0][i]<<' '<<sum2[0][i]<<endl;
            }
            else g[0][i]=n,is2[0][i]=0;
        }
        for(int i=1;i<21;i++)for(int j=1;j<=n;j++)
            g[i][j]=g[i-1][g[i-1][j]],sum2[i][j]=sum2[i-1][j]+sum2[i-1][g[i-1][j]],
            is2[i][j]=is2[i-1][j]&is2[i-1][g[i-1][j]];
        for(int i=1;i<=n;i++)if(nxt[i]>i){
            int x=i;
            if(len1[i]>1){
                x=nxt[i];
                for(int j=20;~j;j--)if(is1[j][x])ans+=sum1[j][x],x=f[j][x];
                ans+=len2[x];
            }
            //assert(i==x || len1[x]<2);
            //cerr<<i<<' '<<x<<' '<<ans<<endl;
            if(i==x || len1[x]==1){
                int y=x,cnt=1;
                x=nxt[x];
                for(int j=20;~j;j--)if(is2[j][x])cnt+=1<<j,ans+=sum2[j][x],x=g[j][x];
                if(lst[x]==i || len1[lst[x]]>1)ans+=len2[x];
                /*if(cnt){
                    cnt--;
                    for(int j=20;~j;j--)if(cnt>>j&1)y=g[j][y];
                    cerr<<cnt<<' '<<y<<endl;
                    if(y==i && nxt[i]-i>1 || len1[y]>1)ans+=len2[x];
                }*/
            }
            //assert(!len1[x]);
            //cerr<<"ANS:"<<i<<' '<<ans<<' '<<x<<endl;
            if(!len2[x])continue;
            x=nxt[x];
            for(int j=20;~j;j--)if(is3[j][x])ans+=sum3[j][x],x=f[j][x];
            //cerr<<"ANS:"<<i<<' '<<ans<<endl;
        }
        return ans;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&CCFILOVEYOU,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(CCFILOVEYOU<=10 || n<=10)printf("%lld\n",sub1::solve());
        else if(CCFILOVEYOU==11 || CCFILOVEYOU==12)printf("%lld\n",sub2::solve());
        else if(CCFILOVEYOU==13 || CCFILOVEYOU==14)printf("%lld\n",sub3::solve());
        else printf("%lld\n",sub4::solve());
    }
}
