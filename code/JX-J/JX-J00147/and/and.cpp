#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],m,sum,x=(1<<31)-1;
bool vis[N];
int w[4*N];

bool cmp(int a,int b){return a>b;}

void dfs(int x,int ans){
    if(x==m+1){
        sum=max(sum,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,ans&a[i]);
            vis[i]=0;
        }
    }
    return;
}

void build(int u,int L,int R){
    if(L==R){
        w[u]=a[L];
        return;
    }
    int mid=(L+R)>>1;
    build(2*u,L,mid);build(2*u+1,mid+1,R);
    w[u]=w[2*u]&w[2*u+1];
    return;
}

int query(int u,int L,int R,int l,int r){
    if(L>r||R<l) return x;
    if(L>=l&&R<=r) return w[u];
    int mid=(L+R)>>1;
    return query(2*u,L,mid,l,r)&query(2*u+1,mid+1,R,l,r);
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        dfs(1,x);
        cout<<sum;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++) sum=max(sum,a[i]);
        cout<<sum;
        return 0;
    }
    if(m==n){
        sum=x;
        for(int i=1;i<=n;i++) sum=sum&a[i];
        cout<<sum;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                sum=max(sum,a[i]&a[j]);
            }
        }
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        build(1,1,n);
        for(int i=1;i<=n;i++){
            if(i==n) sum=max(sum,query(1,1,n,1,i-1));
            else sum=max(sum,query(1,1,n,1,i-1)&query(1,1,n,i+1,n));
        }
        cout<<sum;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    return 0;
}
