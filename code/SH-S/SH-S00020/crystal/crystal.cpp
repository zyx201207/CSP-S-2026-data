#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;

ll n,m,a[N+5],s[N+5];
int ans;

bool check(int i,int j){//j!!
    return a[j+1]*(j-i+1)-(s[j]-s[i-1])<=m;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<n;i++){
        int l=1,r=i+1,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(check(mid,i)) r=mid;
            else l=mid+1;
        }
        if(l-1>0 && check(l-1,i)) l--;
        ans=max(ans,i-l+2);
    }
    cout<<ans<<'\n';
    return 0;
}
