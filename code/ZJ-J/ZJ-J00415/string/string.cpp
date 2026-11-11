#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct st{
	ll s;
	char c;
}a[200001],aa[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n,cnt = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		char c;
		cin >> x >> c;
		if(i > 1 and c == a[cnt].c)
			a[cnt].s += x;
		else a[++cnt].c = c,a[cnt].s = x;
	}for(int i = 1;i <= cnt;i++)aa[i].c = a[i].c,aa[i].s = a[i].s;
	n = cnt;
	ll m1 = 0,m2 = 0;
	int j = n;
	for(int i = 1;i < j;i++){
		while(a[i].s){
			if(a[i].c != a[j].c)
				m1 += min(a[j].s,a[i].s);
			a[i].s = max(0ll,a[i].s - a[j].s);
			a[j].s = max(0ll,a[j].s - a[i].s);
			if(a[j].s == 0)j--;
		}
	}
	j = 1;
	for(int i = n;i > j;i--){
		while(aa[i].s){
			if(aa[i].c != aa[j].c)
				m2 += min(aa[j].s,aa[i].s);
			aa[i].s = max(0ll,aa[i].s - aa[j].s);
			aa[j].s = max(0ll,aa[j].s - aa[i].s);
			if(aa[j].s == 0)j++;
		}
	}
	cout << min(m1,m2);
	return 0;
}