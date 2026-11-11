#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

//find a list of number:sum(|maxv - numi|)=> min
ll n,m;
ll a[N],s[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    a[0] = 0;
    for(int i = 1;i <= n;i ++)
            cin >> a[i];
    sort(a + 1,a + n + 1);

    memset(s,0,sizeof s);
   for(int i = 1;i <= n;i ++){
        s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
   }

   ll cnt = 0;// ans = max(r - l + 1) && ((s[r] - s[l])/2 <= m)
   ll tmp = 0;
   ll l = 1,r = 1;
   while(r <= n){
        if((s[r] - s[l]) <= m + (l - 1) * (a[r] - a[l])) cnt = max(cnt,r - l + 1);
        else l ++;
        r ++;
   }

   cout << cnt <<'\n';
    return 0;
}

/*
5 5
1 2 4 8 9
*/
