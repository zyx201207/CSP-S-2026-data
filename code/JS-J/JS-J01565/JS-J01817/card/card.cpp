#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cur[500005],len,ans[300005];
int last[300005];
void solve(int x){
    for(int i=x;i<=n;i++){
        if(last[a[i]]){
            len=last[a[i]];
            for(int j=last[a[i]];j<i;j++){
                last[cur[j]]=0;
                cur[j]=0;
            }
            last[a[i]]=len;
            cur[len]=a[i];
        }else{
            cur[++len]=a[i];
            last[a[i]]=len;
        }
    }
    for(int i=1;i<=len;i++){
        ans[cur[i]]++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        len=0;
        memset(last,0,sizeof(last));
        solve(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
