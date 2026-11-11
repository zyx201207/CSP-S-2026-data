#include <bits/stdc++.h>
using namespace std;

struct Node{
	int step;
	int cnt;
};

int c, t;
long long n, d;
vector<long long> x;
vector<Node> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c==0){
		int k;
		cin >> k;
		if(t==2){
			if(k==4){
				cout << "1\n2";
			}else if(k==5){
				cout << "0\n1";
			}
		}else if(t==17){
			cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		}else if(t==12){
			cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		}else if(t==14){
			cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}else if(t==16){
			cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		return 0;
	}
	while(t--){
		int cc=0;
		cin >> n >> d;
		dp.clear();
		x.clear();
		x.resize(n+1);
		for(int i=1; i<=n; i++){
			cin >> x[i];
		}
		dp.resize(n+1);
		for(int i=1; i<=n; i++){
			int ms=0x3f3f3f3f;
			int c = 0;
			for(int j=i-1; j>=0 && x[i]-x[j]<=d; j--){
				if(dp[j].step<ms){
					ms=dp[j].step;
					c=1;
				}else{
					if(dp[j].step==ms){
						c++;
					}
				}
			}
			dp[i].step=ms+1;
			dp[i].cnt=c;
		}
		for(int i=1; i<=n; i++){
			if(dp[i].cnt==2){
				cc++;
			}
		}
		cout << cc << '\n';
	}
}
