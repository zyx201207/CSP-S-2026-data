#include<bits/stdc++.h>
#define int long long
constexpr int N=2e5+5;
using namespace std;
int n,m,a[N],ans;
void dfs(int u,int v,int sum) {
    if (sum<=ans and sum!=-1) {
        return;
    }
    if (v==m) {
        ans=max(ans,sum);
        return;
    }
    if (u==n+1) {
        return;
    }
    dfs(u+1,v,sum);
    if (sum==-1) {
        sum=a[u];
    }
    dfs(u+1,v+1,sum&a[u]);
    return;
}
signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxx=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if (n<=20) {
        dfs(1,0,-1);
        cout<<ans<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
    if (n==m) {
        int ans=a[1];
        for (int i=2;i<=n;i++) {
            ans&=a[i];
        }
        cout<<ans<<"\n";
        return 0;
    }
    if (m==1) {
        int ans=0;
        for (int i=1;i<=n;i++) {
            ans=max(ans,a[i]);
        }
        cout<<ans<<"\n";
        return 0;
    }
    if (m==2) {
        int ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    if (maxx<4) {
        int sum1=0,sum2=0,sum3=0;
        for (int i=1;i<=n;i++) {
            if (a[i]==1) {
                sum1++;
            }
            if (a[i]==2) {
                sum2++;
            }
            if (a[i]==3) {
                sum3++;
            }
        }
        if (sum3>=m) {
            cout<<"3\n";
        } else if (sum2+sum3>=m) {
            cout<<"2\n";
        } else if (sum1+sum3>=m) {
            cout<<"1\n";
        } else {
            cout<<"0\n";
        }
        return 0;
    }
    int ans=INT_MAX;
    for (int i=1;i<=n;i++) {
        ans=min(ans,a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
