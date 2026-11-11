#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=5e5+10;
int n,m,a[N];
int l,p[N],ct[N],ans=1;;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    p[1]=a[1];
    ct[1]=1;
    l=1;
    for(int i=2;i<=n;++i){
        if(a[i]!=a[i-1]){
            l++;
            p[l]=a[i];
        }
        ct[l]++;
    }
    for(int i=1;i<=l;++i){
        int cnt=ct[i],k=m;
        for(int j=i-1;j>=1;--j){
            int t=min(ct[j],k/(p[i]-p[j]));
            cnt+=t;
            k-=t*(p[i]-p[j]);
            if(t==0){
                break;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans<<endl;
    return 0;
}