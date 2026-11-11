#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
ll n,m;
ll a[N];
int st[M],lst[M];
ll cnt[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int st=0;
        memset(lst,0,sizeof(lst));
        for(int j=i;j<=n;j++){
            if(lst[a[i]]){
                for(int k=lst[a[i]];k<j;k++) lst[a[i]]=0;
                st=j-1;
            }
            else lst[a[i]]=i;
        }
        for(int i=st+1;i<=n;i++){
            cnt[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
