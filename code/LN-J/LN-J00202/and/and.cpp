#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ri register int
using namespace std;
const int N=2e5+5;
int n,m,w,s;
ll a[N],ans,k[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ri i=1;i<=n;++i)cin>>a[i];
    for(int i=29;i>=0;--i){
        int tmp=0,t=(1<<i);
        ll l[N];
        for(ri j=1;j<=n;++j){
            if((a[j]/t)%2==1){
                l[++tmp]=a[j];
            }
        }
        if(tmp>=m){
            for(ri j=1;j<=tmp;++j)k[j]=l[j];
            w=i;s=tmp;
            break;
        }
    }
    if(s==m){
        ans=k[1];
        for(ri i=2;i<=m;++i)ans=ans&k[i];
        cout<<ans;
        return 0;
    }
    ans=(1<<w);
    ll nk[2][s+5];
    for(ri i=1;i<=s;++i)nk[0][i]=k[i];
    int nl=0,ln=1,mx;
    for(int i=w-1;i>=0;--i){
        int tmp=0,t=(1<<i);
        for(int j=1;j<=s;++j){
            if((nk[nl][j]/t)%2==1)nk[ln][++tmp]=nk[nl][j];
        }
        if(tmp==m){
            ans=nk[ln][1];
            for(ri j=2;j<=m;++j)ans=ans&nk[ln][j];
            cout<<ans;
            return 0;
        }
        if(i==0){
            if(tmp>m)cout<<ans+1;
            else cout<<ans;
            return 0;
        }
        if(tmp>m){
            ans+=(1<<i);
            swap(nl,ln);
            s=tmp;
        }
    }
    cout<<ans;
    return 0;
}
