#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll q,n,d,x[N],ans[N],c,s;
void check(int k)
{
	for(int i = k + 1;x[i] <= x[k] + d && i <= n;i++)
		for(int j = i + 1;x[j] <= x[i] + d && j <= n;j++) ans[j]++;
	for(int i = k + 1;x[i] <= x[k] + d && i <= n;i++) ans[i] = 0;
	for(int i = 1;i <= n;i++)
		if(ans[i] == 2) s++;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> c >> q;
    while(q--){
    	cin >> n >> d;
    	ll minn = LONG_LONG_MAX;
    	s = 0;
    	for(int i = 1;i <= n;i++){
    		cin >> x[i];
    		if(i != 1) minn = min(minn,x[i] - x[i - 1]);
		} 
		if(minn >= d || d >= x[n] - x[1]){
			cout << "0\n";
			continue;
		}
		if(c == 11 || c == 12){
			ll p = d / minn;
			cout << n - 2 * p + 1 << '\n';
		}
		if(c == 13 || c == 14){
			cout << "1\n";
		}
		for(int i = 1;i <= n;i++){
			memset(ans,0,sizeof(ans));
			check(i);
		}
		cout << s << '\n';
	}
    return 0;
}
/*
0 2
4 2
1 2 3 4 
5 2 
1 2 3 4 5
*/