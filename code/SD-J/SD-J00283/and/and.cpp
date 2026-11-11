#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
vector <int> res;
//int res;
int pop_count(int x){
	int ret=0,cur=-1;
	while(x>0){
		cur++;
//		cout << cur << endl;
		if(x&1){
			ret++;
			res.push_back(a[cur]);
//			cout << a[cur];
		}
		x/=2;
	}
//	cout << ret << "\n";
//	for (auto i)
	return ret;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=0;i<n;i++)	cin >> a[i];
//	for (int i=0;i<n;i++)	cout<< a[i];
	int mx=INT_MIN;
	for (int mask=0;mask<(1<<n);mask++){
		int tmpm=pop_count(mask);
//		cout << tmpm << endl;
		if (tmpm!=m){
			res.clear();
			continue;
		}
		int len=res.size();
//		cout << len ;
		res.resize(len);
		int tmp=res[0];
		for (int i=1;i<len;i++){
			tmp&=res[i];
//			cout << res[i]<< " ";
		}
//		cout << endl;
		mx=max(tmp,mx);
//		cout << tmp << endl;
		res.clear();
	}
	
	cout << mx << endl;
//	cout << pop_count(12);
//	for (int i)
	return 0;
}

