#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long x[2000010];
long long ans=LONG_LONG_MAX,num=0;
long long r;
void dfs(long long pos,long long dis) {
    if(pos==r) {
        if(dis==ans) {
            num++;
        }
        if(dis<ans) {
            ans=dis;
            num=1;
        }
    }
    for(long long i=pos+1;i<=r;i++) {
        if(x[i]-x[pos]<=d) {
            dfs(i,dis+1);
        }
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(long long i=1;i<=n;i++) {
            cin >> x[i];
        }
        long long sum=0;
        for(long long i=1;i<n;i++) {
            for(long long j=i+1;j<=n;j++) {
                ans=LONG_LONG_MAX;
                num=0;
                r=j;
                dfs(i,0);
                if(num==2) sum++;
            }
        }
        cout << sum << "\n";
    }   
    return 0;
}
