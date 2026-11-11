#include<bits/stdc++.h>
using namespace std;
//Good luck
//Happy ending
int n;
long long m;
const int maxn=5e5+5;
int a[maxn]={0};
int b[maxn]={0};
int dp[maxn]={0};
long long ans=0;
long long cnt[maxn]={0};
bool vis[maxn]={0};
//5e5
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    if(m==0){//special
        cout<<a[n];
        return 0;
    }

    b[1]=b[0]=0;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }

    int c[maxn]={0};
    c[2]=b[2];
    for(int i=3;i<=n;i++){
        c[i]=c[i-1]+b[i];
    }

    long long sum[maxn]={0};
    sum[0]=sum[1]=0;
    long long ans=0;
    long long cnt=0;
    for(int i=2;i<=n;i++){
        sum[i]=b[i]*(i-1)+sum[i-1];
        if(sum[i]<=m){
            if(sum[i]>=ans)cnt=i;
        }
    }
    cout<<cnt;

    return 0;
}
