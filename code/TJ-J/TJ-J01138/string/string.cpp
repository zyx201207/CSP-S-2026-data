#include <bits/stdc++.h>
using namespace std;
struct str{
	int num;
	char s;
};
vector<str> a;
long long n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		str t;
		cin >> t.num >> t.s;
		a.push_back(t);
	}
	long long l = 0,r = n-1;
	while (l<r){
		long long minn = min(a[l].num,a[r].num);
		a[l].num-=minn;
		a[r].num-=minn;
		if (a[l].s!=a[r].s) cnt+=minn;
		if (a[l].num == 0){
			l++;
		}else{
			r--;
		}
	}
	cout << cnt;
	return 0;
}
