#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],b[N],c[N],n,m;
int ans;

int miku(int l,int r){
    return c[r]-c[l]-(l-1)*(a[r]-a[l]);
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    b[1]=0,c[1]=0;
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++) c[i]=c[i-1]+(i-1)*b[i];
    int pos=lower_bound(c+1,c+n+1,m)-c;
    if(c[pos]>m) pos--;
    int l=1,r=pos,last=miku(l,r),ans=pos;
    for(int i=pos+1;i<=n;i++){
        if(miku(i-ans+1,i)<last){
            l=i-ans+1,r=i;
            while(l>1&&r<n){
                if(miku(l-1,r)>m&&miku(l,r+1)>m) break;
                if(a[r]-a[l-1]<a[r+1]-a[r]) l--,ans++;
                else r++,ans++;
            }
            i=r,last=miku(l,r);
        }
    }
    cout<<ans;
    return 0;
}
