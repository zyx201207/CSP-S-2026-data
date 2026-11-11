#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],b[500005];
int c[500005];
bool check(int l,int r){
    int res=0;
    for(int i=l+1;i<=r;i++){
        res+=((b[i]-b[i-1])*(i-l));
    }
    return res<=m;
}

signed main(){
    freopen("crystal.in","r",stdin);

    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>=5000){
        int cnt=0;
        for(int i=2;i<=n;i++){
            cnt+=(a[i]-a[i-1])*(i-1);
            if(cnt>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    else if(n<5000){
        b[1]=0;
        for(int i=2;i<=n;i++){
            b[i]=a[i]-a[i-1];
            b[i]+=b[i-1];
        }
        int ans=0;

        b[n+1]=1e18+5;
        int r=1;
        for(int l=1;l<=n&&r<=n;l++){
            while(r<=n&&check(l,r)) r++;
            r--;
            ans=max(ans,r-l+1);
        }
        cout<<ans;
    }

    return 0;
}
