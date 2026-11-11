#include<bits/stdc++.h>
#include<bits/extc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace __gnu_cxx;
using namespace std;
int n,m,maxn=1,a[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,sum=0;
    for(int r=2;r<=n;r++){
        sum+=(a[r]-a[r-1])*(r-l);
        while(l<r&&sum>m){
            sum-=a[r]-a[l];l++;
        }
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    return 0;
}
