#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
void solve(int p){
    int val=1<<p,cnt=0,b[N];
    for(int i=1;i<=n;i++)
        if(a[i]>=val)
            b[++cnt]=a[i];
    if(cnt>=m){
        ans+=val;
        for(int i=1;i<=cnt;i++)
            a[i]=b[i]-val;
        n=cnt;
    }
    else
        for(int i=1;i<=n;i++)
            if(a[i]>=val)
                a[i]-=val;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=30;i>=0;i--)
        solve(i);
    cout<<ans;
    return 0;
}
