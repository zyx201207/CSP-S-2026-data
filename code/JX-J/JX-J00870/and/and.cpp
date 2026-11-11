#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long ch[200010];
long long ans=0;
long long n,m;
void dfs(long long pos,long long sum) {
    if(pos==n+1) {
        if(sum==m) {
            long long t=-1;
            for(long long i=1;i<=n;i++) {
                if(ch[i]==1) {
                    if(t==-1) t=a[i];
                    else t=t&a[i];
                }
            }
            ans=max(ans,t);
        }
        return;
    }
    ch[pos]=0;
    dfs(pos+1,sum);
    ch[pos]=1;
    dfs(pos+1,sum+1);
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++) {
        cin >> a[i];
    }
    if(n<=20) {
        dfs(1,0);
        cout << ans;
    }
    else if(n<=2000) {
        if(m==1) {
            for(long long i=1;i<=n;i++) {
                ans=max(ans,a[i]);
            }
        }
        else if(m==n) {
            ans=a[1];
            for(long long i=2;i<=n;i++) {
                ans&=a[i];
            }
        }
        else if(m==2) {
            ans=a[1]&a[2];
            for(long long i=1;i<=n-1;i++) {
                for(long long j=i+1;j<=n;j++) {
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        cout << ans;
    }
    else {
        sort(a+1,a+n+1);
        long long ans=a[n];
        for(long long i=n;i>=n-m+1;i--) {
            ans&=a[i];
        }
        cout << ans;
    }
    return 0;
}