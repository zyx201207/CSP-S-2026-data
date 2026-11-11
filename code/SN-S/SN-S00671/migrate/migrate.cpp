#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
const int M = 5005;
int c,t,jl[N],d,n,minn[M][M],sha[M][M];
void dfs(int s,int q,int cnt){
	if(cnt > minn[q][s])
		return;
	sha[q][s]++;
	if(s >= n)
		return;
	int p = jl[s]+d;
	for(int i = s+1;i <= n && p >= jl[i];i++)
		dfs(i,q,cnt+1);
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	system("fc migrate.out migrate.ans");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		if(n <= 5000){
			for(int i = 1;i <= n;i++)
				cin >> jl[i];
			for(int i = 1;i < n;i++){
				int nw = jl[i],cnt=0;
				for(int j = i+1;j <= n;j++){
					sha[i][j] = 0;
					if(nw < jl[j]){
	//					cout << nw << '\n';
						nw += d;
						cnt++;
					}
					if(nw < jl[j+1])
						nw = jl[j];
	//				cout << i << ' ' << j << "助我破鼎\n";
					minn[i][j] = cnt;
	//				cout << i << ' ' << j << " 小 " << minn[i][j] << '\n';
				}
			}
			for(int i = 1;i <= n;i++)
				dfs(i,i,0);
			int ans = 0;
			for(int i = 1;i < n;i++){
				for(int j = i+1;j <= n;j++){
					if(sha[i][j] == 2){
						ans++;
					}
	//				cout << sha[i][j] << ' ';
				}
	//			cout << '\n';
			}	
			cout << ans << '\n';
		}
		else if(c == 11 || c == 12){
			int gc = 0;
			for(int i = 1;i <= n;i++){
				cin >> jl[i];
				if(i == n)
					gc = jl[i]-jl[i-1];
			}
			if(d < gc){
				cout << 0 << '\n';
				continue;
			}
			int p = 2*d/gc-1;
//			cout << "n = " << n << " 公差：" << gc << "，单次条约覆盖区块数：" << d/gc << '\n';
			if(p == 1 || p == 2 || p >= n)
				cout << 0 << '\n';
			else
				cout << n-p << '\n';
		}
	}
	return 0;
}
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

ANS:6
CCF Just_do_it.png
luoguID:Flynewcat
尽管我无法证明它的对错，但我坚信它是对的！ 
*/
