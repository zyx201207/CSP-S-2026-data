#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0) {putchar('-');x=-x;}
    if(x<10){putchar(x+'0');return;}
    else {write(x/10);putchar(x%10+'0');}
}
int st[N][30],d[N],lg[N],a[N];int n,m;
bool check(int l,int r){
    int j=lg[r-l+1];
    int mx=max(st[l][j],st[r-(1<<j)+1][j]),sum=d[r]-d[l-1];
    if((r-l+1)*mx-sum<=m) return 1;
    return 0;
}
int find(int s,int l,int r){
    if(l>=r-1) return l-s+1;
    int mid=(l+r)>>1;
    if(check(s,mid)) return find(s,mid,r);
    else return find(s,l,mid-1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) st[i][0]=a[i];
    for(int i=1;i<=n;i++) d[i]=d[i-1]+st[i][0];
    lg[1]=0;
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=LONG_LONG_MIN;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    int ans=1;
    for(int i=1;i<n;i++) ans=max(ans,find(i,i,n));
    cout<<ans;
    return 0;
}
//worried by small example,mistake this question
//16:05 ACed