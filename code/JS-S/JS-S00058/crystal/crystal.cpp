#include<bits/stdc++.h>
#define int long long

using namespace std;
int n,m;
int a[500005];
int s[500005];
int ans=1;
priority_queue<int>q;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=n;i>=1;i--){
        a[i]=q.top();q.pop();
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])>m)l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}

