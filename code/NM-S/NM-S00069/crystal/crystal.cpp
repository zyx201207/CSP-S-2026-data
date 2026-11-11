#include <bits/stdc++.h>
using namespace std;
long n,m;
bool flag=true;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    vector<long> a(n,0),jian(n,0),sum(n,0);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++) {
        jian[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+jian[i]*i;
        if(jian[i]!=jian[i-1] && i>1) flag=false;
    }
    if(m>=sum[n-1]) {
        cout << n << '\n';
    } else if(flag) {
        long i=1;
        while(m>=i*jian[1]) {
            m-=i*jian[1];
            i++;
        }
        cout << i << '\n';
    } else {
        long l=0,r=1,ml=1;
        while(sum[r]-sum[l]<=m && l<=r && r<n) {
            ml=max(r-l+1,ml);
            if(sum[r]-sum[l]>m) {
                if(n-r+1<=ml) break;
                l=r,r++;
                continue;
            }
            if(sum[l+1]-sum[l]>=sum[r+1]-sum[r]) {
                r++;
                if(sum[r]-sum[l]>m) l++;
                continue;
            }
            r++;
        }
        cout << ml << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
