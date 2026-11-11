#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+7;
int a[MAXN],s[MAXN];
int n,m;
int ans=0;
int mn;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //s[i]=s[i-1]+a[i];
        mn=min(mn,a[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]-=mn;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=0;
    for(r=1;r<=n;r++){
        while(a[r]*(r-l+1)-(s[r]-s[l-1])>m){
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}