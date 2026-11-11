#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();};
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();};
    return x*f;
}
const int N=5e5+10;
int m,n,a[N],pre[N],ans=-1;
bool vis(int l,int r){
    int sum1=pre[r]-pre[l-1];
    int sum2=(r-l+1)*a[r];
    return m>=abs(sum2-sum1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int l=1;l<=n;l++){
        int nl=l,nr=n,weizhi=l;
        while(nl<=nr){
            int mid=(nl+nr)>>1;
            if(vis(l,mid)){
                nl=mid+1;
                weizhi=mid;
            }else{
                nr=mid-1;
            }
        }
        ans=max(ans,(weizhi-l+1));
    }
    cout<<ans;
    return 0;
}
