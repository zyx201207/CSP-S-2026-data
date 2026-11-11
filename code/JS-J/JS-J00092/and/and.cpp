#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+5;
int n,m,a[N],qp[N];
bool cmp(int a,int b){return a>b;}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++) cout << a[i] << '\n';
    qp[0] = 1;
    for(int i=1;i<=31;i++) qp[i] = qp[i-1] * 2;
    //for(int i=1;i<=31;i++) cout << qp[i] << ' ';
    //cout << '\n';
    int ans = qp[31]-1;
    int cnt=1,i=1;
    while(cnt<=m && i<=n) {
        bool flag = 1;
        for(int j=1;j<=31;j++) if(a[i]==qp[j]) {flag = 0;}//cout << i << '-' << j << '\n';}
        if(flag) {ans = ans & a[i];cnt++;}//cout << ans << endl;}
        i++;
    }
    cout << ans;
    return 0;   
}