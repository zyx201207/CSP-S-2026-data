#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans[300010],posl[300010];
bool p[300010];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(long long i=1;i<=n;i++) {
        cin >> a[i];
    }
    for(long long i=1;i<=n;i++) {
        memset(p,0,sizeof(p));
        for(long long j=i;j<=n;j++) {
            if(p[a[j]]==0) {
                p[a[j]]=1;
                posl[a[j]]=j;
            }
            else {
                long long e=posl[a[j]];
                for(long long t=e;t<j;t++) {
                    p[a[t]]=0;
                    posl[a[t]]=0;
                }
                p[a[j]]=1;
                posl[a[j]]=j;
            }
        }
        for(long long j=1;j<=m;j++) {
            if(p[j]) {
                ans[j]++;
            }
        }
    }
    for(long long i=1;i<=m;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}