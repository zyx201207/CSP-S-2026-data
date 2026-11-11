#include <iostream>
#include <cmath>
using namespace std;
int n,m;
int a[200005];
t main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int maxn = -1,cnt,chuli=0;
    if(m==1) for(int i=1;i<=n;i++) if(a[i]>maxn) {maxn = a[i];chuli=1;}
    if(m==2) for(int i=1;i<=n;i++) for(int j=1;i<=n;i++) if(a[i]&a[j]>maxn) {maxn = a[i]&a[j];chuli=1;}
    if(m==n-1) for(int i=1;i<=n;i++) {
        if(i==1) cnt = a[2]&a[3];
        else if(i==2) cnt = a[1]&a[3];
        else cnt = a[1]&a[2];
        for(int j=4;j<=n;j++) if(j!=i) cnt = cnt&a[j];
        if(cnt > maxn) maxn =cnt;
        chuli=1;
    }
    if(m==n) {
        cnt = a[1]&a[2];
        for(int j=3;j<=n;j++) cnt = cnt&a[j];
        maxn = cnt;
        chuli=1;
    }
    bool b=1;
    for (int i=1;i<=n;i++) if((a[i]+1)&a[i]!=0) b=0;
    if(b=1){
        qsort(a+1,a+n+1);
        maxn = a[n-m+1];
        chuli=1;
    } 
    if(chuli = 0) maxn = 1;
    cout << maxn;
    return 0;
}
