#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N],n,m,ans=-1,v[N];
bool cmp(int pre,int nxt){
    return pre>nxt;
}
int js(int sy,int z){
    if(sy==0)return z;
    int zt=-1,xw;
    for(int j=1;j<=n;j++){
        if(v[j]==0&& ((z&a[j])>zt)){
            zt=(z&a[j]);
            xw=j;
        }
    }
    v[xw]=1;
    return js(sy-1,zt);
}
int main(){
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        v[i]=1;
        ans=max(ans,js(m,a[i]));
    }
    cout<<ans;
    return 0;
}
