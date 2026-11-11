#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=0;
ll a[500005],m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=-1e13;
    int l=0,r=0;
    for(r=1;r<=n;r++){
        m=m-(a[r]-a[r-1])*(r-l);
        while(m<0){
            m=m+(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
