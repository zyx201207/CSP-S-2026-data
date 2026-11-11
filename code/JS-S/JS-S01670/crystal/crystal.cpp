#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],ans[N],n,m,cnt;
int read(){
    int f=1,x=0;
    char ch='\n';
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-') f=-1;
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return f*x;
}
void write(int x){
    if(x<0){
        cout<<'-';
        x*=-1;
    }
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    x%=10;
    putchar(x+'0');
}
int tree[N<<2],treemaxn[N<<2];
void build(int dep,int l,int r){
    if(l==r){
        tree[dep]=0;
        treemaxn[dep]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(dep<<1,l,mid);
    build(dep<<1|1,mid+1,r);
    treemaxn[dep]=max(treemaxn[dep<<1],treemaxn[dep<<1|1]);
    tree[dep]=tree[dep<<1]+tree[dep<<1|1]+(mid-l+1)*(treemaxn[dep]-treemaxn[dep<<1]);
    return ;
}
int query(int dep,int l,int r,int x,int y,int z){
    if(x<=l&&r<=y) return tree[dep]+(z-treemaxn[dep])*(r-l+1);
    if(r<x||y<l) return 0;
    int mid=(l+r)>>1;
    return query(dep<<1,l,mid,x,y,z)+query(dep<<1|1,mid+1,r,x,y,z);
}
bool check(int xxx,int v){
    int re=query(1,1,n,xxx,v-1,a[v]);
    if(re>m) return false;
    return true;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    //cin>>n>>m;
   // cout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++){
        a[i]=read();
        //cout<<i<<endl;
        //cin>>a[i];
    }
    sort(a+1,a+1+n);
    build(1,1,n);
    int maxn=1;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            ans[i]=ans[i-1]+1;
            maxn=max(ans[i],maxn);
            continue;
        }
        int l=1,r=i-1;
        while(l<r){
            //cout<<l<<' '<<r<<endl;
            int mid=(l+r)>>1;
            if(check(mid,i)) r=mid;
            else l=mid+1;
        }
        ans[i]=i-l+1;
        maxn=max(maxn,ans[i]);
    }
    write(maxn);
    putchar('\n');
    //cout<<maxn;
    return 0;
}
/*
5 5
1 2 4 8 9

*/
