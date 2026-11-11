#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int N=500055;
int n,m,a[N],pre[N];
bool check(int len){
    for(int j=1;j<=n-len+1;j++){
        int k=j+len-1;
        int x=pre[j-1]-pre[k]+(k-j+1)*a[k];
        if(x<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
