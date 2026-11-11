//图灵保佑
//\|/
#include<bits/stdc++.h>
using namespace std;
long long n,m;

long long a[500005];
long long b[500005];
bool biggest_dick;//判断是否属于等于i的数字 
bool same_num;//判断是否属于等差数列 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m == 0 || n == 0){
		cout<<0;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		if(a[i] != i){
			biggest_dick = 1;
		}
		if(i != 1){
			if(a[i] - a[i - 1] != a[2] - a[1]){
				same_num = 1;
			}
		}
	}
	
	if(same_num == 0){
		cout<<min(n,(m / (a[2] - a[1])) + 1);
		return 0;
	}
	if(biggest_dick == 0){
		cout << min(n,m);
		return 0;
	}
	sort(a + 1,a + 1 + n);
	long long maxx = -1;
	for(int j = 1; j <= n; j++) {
		long long dick = m;
		long long cnt = 0;

		for(int i = j; i <= n; i++) {
			long long t = a[i] - a[i - 1];
			long long _91 = (i - 1) * t;
			if(_91 > dick) {
				break;
			}
			dick -= _91;
			cnt++;
		}
		maxx = max(maxx,cnt);
	}

	cout<<maxx;
	return 0;
}
