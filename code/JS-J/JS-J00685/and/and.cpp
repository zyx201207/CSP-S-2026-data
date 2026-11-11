#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005],ans;
//hyw
void bfs(int step,int value,int now){
    value&=b[now];
    if(step==m) {ans=max(ans,value);return;}
    for(int i=now-1;i>=1;i--){
        if(b[i]<ans) break;
        bfs(step++,value,b[i]);
    }
}
signed main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i]=a[i];

    }
    sort(b+1,b+1+n);
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(b[i]!=i-1) flag=1;
    }
    if(m==1) cout<<b[n];
    else if(flag==0) cout<<b[n-m+1];
    else{
        bfs(1,b[n],n);
        cout<<ans;
    }

    return 0;


}
