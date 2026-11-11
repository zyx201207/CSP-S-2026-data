#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2,j=1;i<=n;++i){
        m-=(a[i]-a[i-1])*(i-j);
        while(m<0 && j<i){
            m+=a[i]-a[j];
            ++j;
        }
        ans=max(ans,i-j+1);
    }
    cout<<max(1ll,ans);
    return 0;
}

