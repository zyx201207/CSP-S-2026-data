#include<bits/stdc++.h>
#include<bits/extc++.h>
#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
const int MAXN=5e5;
int n;
long long m,a[MAXN+11],pre[MAXN+11];
void main_init(){

    return;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int maxx=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,pos=-1;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)
                r=mid-1,pos=mid;
            else
                l=mid+1;
        }
        if(~pos)
            maxx=max(maxx,i-pos+1);
    }
    cout<<maxx<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    main_init();
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}