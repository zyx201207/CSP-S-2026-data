#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;

int n,ans=1;
ll m,a[N],pre[N];

bool check(int mid,int cur){
    if((mid-cur)*a[cur]-(pre[mid]-pre[cur])>m)return false;
    return true;
}


int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r>>1)+1;
            if(check(mid,i)){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,l-i+1);
    }
    cout<<ans;
    return 0;
}
