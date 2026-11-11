#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll n,m,a[N],cnt=1,tmp,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        tmp=m;
        for(int j=i+1;j<n;j++){
            tmp=tmp-(a[j]-a[j-1])*(j-i);
            if(tmp>=0)cnt++;
            else break;
        }
       ans=max(ans,cnt);
       cnt=1;
    }
    cout<<ans;
    return 0;
}
