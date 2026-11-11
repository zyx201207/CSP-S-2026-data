#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;
typedef long long LL;
const int N =500000  + 10;
int cnt = 0;//

//crystal

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	LL m;//m is opreration counts
	cin >> n >> m;
	vector<LL> a(n + 1,0);
	vector<LL> d(n + 5,0);//dist
	vector<LL> s(n + 5,0);//sum pre

	//read
	for(int i = 1; i <= n ; i++) cin >> a[i];

	//sort
	sort(a.begin() + 1,a.end());
//	vector<LL> b(n + 1,0)//qu chong array
	vector<int> c(n + 1,0);//记录每个节点重复元素个数
	int bcfc = 0;
	for(int i = 1; i <= n ; i ++) {
		//int c_cnt = 0;
		int j = i;
		while(a[j] == a[i]) {
			//c_cnt ++;
			j ++;
		}
		c[++bcfc] = j - i;
		i = j - 1;
	}
	a.erase(unique(a.begin()+1,a.end()),a.end());
	cnt = a.end() - a.begin() -1;
	//d array
	for(int i = 1; i <= cnt; i ++ )  d[i] = a[i] - a[i -1];
	d[1]  = 0;
	for(int i = 1; i <= cnt; i ++) s[i] = s[i-1] + d[i];

	//mei ju
	int ans = c[1];
	for(int i = 2; i <= cnt; i ++) {
		//m
		int res = c[i];
		//int t = m / d[i];//前一个最多可以覆盖t个
		int j = i - 1;
		LL pp = s[i] -s[j];
		LL totv = m;
		while(totv > 0) {
			if( pp * c[j] >= totv ) {
				res += min((LL)c[j],(totv / pp));
				break;
			}
			res += c[j];
			totv -= pp * c[j];
			j --;
			pp = s[i] - s[j];


		}
		ans = max(ans,res);
	}


	cout << ans << '\n';

//	fclose(stdin);
//	fclose(stdout);

	return 0;
}
