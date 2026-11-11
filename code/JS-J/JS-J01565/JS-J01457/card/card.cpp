#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],sum[500005],cnt=1,ans1[300005];
bool vis[500005]={false};
inline ll read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-48);
        ch=getchar();
    }
    return x*f;
}
ll fd(ll x){
    for(int i=1;i<=n;i++){
        if(x==sum[i]);
        return i;
    }
    return -1;
}
int main(){
    //freopen("card.in","r",stdin);
   // freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        cnt=1;
        for(int j=i-1;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]=1;
                sum[cnt]=a[j];
                cnt++;
            }else{
                int ks=fd(a[j]);
                for(int k=ks;k<j;k++){
                    sum[k]=0;
                    vis[a[k]]=0;
                }
                cnt=ks++;
                sum[ks]=a[j];
            }
        }
        for(int k=1;k<=n;k++){
            ans1[sum[k]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans1[i]<<' ';
    return 0;
}
