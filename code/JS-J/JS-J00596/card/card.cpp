#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;;
int n,m;
int a[N];
int nex[N],la[N],ans[M],cnt,pl[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(la[a[i]]==0){
            la[a[i]]=i;
            nex[i]=0;
        }
        else{
            nex[i]=la[a[i]];
        }
    }
    for(int i=1;i<=n;i++){
        cnt++;
        if(nex[i]!=0){
            pl[nex[i]]+=cnt;
            cnt=0;
        }
        else{
            cnt+=pl[i];
            ans[a[i]]+=cnt;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
