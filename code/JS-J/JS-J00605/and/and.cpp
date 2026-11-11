#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1,minn=INT_MAX,maxnum=-1;
bool flag=1,flag2=1,flag3=1,f[200005];
void dfs(long long n,long long k){
    if(k==m){maxnum=max(maxnum,n);return;}
    for(int i=1;i<=n;i++){
        if(!f[i]){
            f[i]=1;
            dfs(n&a[i],k+1);
            f[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long t2=n;
    while(t2!=1){
        if(t2%2){flag3=0;break;}
        t2/=2;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
        long long t=a[i]+1;
        if(a[i]!=i-1)flag2=0;
        while(t!=1){
            if(t%2){
                flag=0;
                break;
            }
            t/=2;
        }
    }
    int sand=a[1];
    for(long long i=2;i<=n;i++)sand&=a[i];
    if(m==1){cout<<maxn;return 0;}
    if(m==n){cout<<sand;return 0;}
    if(m==2){
        long long ma=-1;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    if(flag){
        sort(a+1,a+1+n,greater<long long>());
        cout<<a[n-m+1];
        return 0;
    }
    if(maxn<4){
        sort(a+1,a+1+n,greater<long long>());
        long long sum=a[1];
        for(long long i=2;i<=m;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    if(flag2&&flag3){
        long long sum=a[n];
        for(long long i=n-1;i>=n-m+1;i--)sum&=a[i];
        cout<<sum;
        return 0;
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        dfs(a[i],1);
        f[i]=0;
    }
    cout<<maxnum;
return 0;
}
