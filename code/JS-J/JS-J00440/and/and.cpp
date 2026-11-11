#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,a[N],b[N],ans,f[32];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    int yn=n,yw=31;
    while(yw>=1&&yn>=1){
        for(int i=1;i<=yn;i++){
            int p=b[i],cnt=0;
            while(p){
                ++cnt;
                f[cnt]+=(p%2);
                p/=2;
            }
        }
        int fg=0;
        for(int i=yw;i>=1;i--){
            if(f[i]>=m){
                yw=i-1;
                fg=1;
                break;
            }
        }
        if(!fg){
            yw=0;
        }
        for(int i=1;i<=yw;i++){
            f[i]=0;
        }
        int cnt=0;
        for(int i=1;i<=yn;i++){
            int q=b[i]%(1<<(yw+1));
            if(q/(1<<yw)){
                b[++cnt]=q%(1<<yw);
            }
        }
        yn=cnt;
    }
    for(int i=1;i<=31;i++){
        if(f[i]>=m){
            ans+=(1<<(i-1));
        }
    }
    cout<<ans;
    return 0;
}
