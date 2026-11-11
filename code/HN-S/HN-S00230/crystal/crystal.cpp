#include<bits/stdc++.h>
#define write ios::sync_with_stdio(0),
#define by cin.tie(0),
#define HN_S00230 cout.tie(0)
#define fori for(int i = 1; i <= n; i ++)
#define int long long
const int N = 5e5 + 5;
long long n,x,a[N],Sn,m[N],cnt;
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
signed main(){
	write by HN_S00230;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> x;
	fori cin >> a[i];
	fori Sn += a[i];
	cout << Sn << endl;
	long long maxn = -1;
	fori{
	    m[i] = n * a[i] - Sn;
	    if(m[i] <= x){
            maxn = max(maxn,n);
	    }else{
            sort(m + 1, m + n + 1,cmp);
            for(int j = 1;m[i] > x; j ++){
                m[i] -= abs(a[j] - a[i]);
                cnt ++;
            }
            maxn = max(maxn,n-cnt);
	    }
	}
	cout << maxn;
	return 0;
}
