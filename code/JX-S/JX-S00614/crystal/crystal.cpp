#include <bits/stdc++.h>
using namespace std;
constexpr int N=500005;
long long n,m;
long long num[N],pre[N];
int l,r,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+num[i];
    }
    for (int i=1;i<=n;i++){
        l=1;r=i;
        while (l<r){
            int mid=(l+r)/2;
            if ((i-mid+1)*num[i]-(pre[i]-pre[mid-1])>m)l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    cout<<'\n';
    return 0;
}
