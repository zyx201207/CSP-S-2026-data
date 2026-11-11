#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
int M,n;
int dfs(int x,int cnt,int res){
    if(cnt==M){
        return res;
    }
    if(x==n&&cnt<M)return 0;
    int ma=0;
    for(int i=x+1;i<=n;i++){
        int y=dfs(i,cnt+1,res&a[i]);
        ma=max(ma,y);
    }
    return ma;
}
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("and3.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    M=read();
    for(int i=1;i<=n;i++){
        a[i]=read();

    }
    int ans=0;
    if(M==2){
   for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
   }
    }else if(M==1){
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
    }
    else if(M==n){
        ans=a[1];
            for(int i=2;i<=n;i++)ans=ans&a[i];
    }else if(n<=20){
        for(int i=1;i<=n;i++){
            ans=max(ans,dfs(i,1,a[i]));
        }
    }
    else{
        sort(a+1,a+1+n,greater<int>());
        ans=a[1];
        for(int i=2;i<=M-1;i++)ans=ans&a[i];
    }
   cout<<ans;
    return 0;
}
