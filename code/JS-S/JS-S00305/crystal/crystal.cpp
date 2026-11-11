#include<bits/stdc++.h>
#define int long long
#define MAXN 500005
using namespace std;
int n,m;
int a[MAXN];
bool cmp(int x,int y){
    return x<y;
}
int now;
int ans;
signed main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=1;
    for (int r=1;r<=n;r++){
        now+=(a[r]-a[r-1])*(r-l);
        while (now>m){
            now-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;

    return 0;

}
