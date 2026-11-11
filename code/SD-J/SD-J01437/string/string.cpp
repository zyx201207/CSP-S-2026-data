#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node{
	int id;
	long long a;
	char c;
}s1[N], s2[N];
int n;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long tot = 0;
	for(int i = 1; i <= n; i ++){
		cin >> s1[i].a >> s1[i].c;
		s2[n - i + 1].a = s1[i].a;
		s2[n - i + 1].c = s1[i].c;
		tot += s1[i].a;
	}
	long long ans = 0;
	node last1, last2;
	last1.a = 0;
	last1.id = 0;
	last2.a = 0;
	last2.id = 0;
	long long i = 0;
	while(i < tot){
		if(last1.a == 0){
			last1.id++;
			last1.c = s1[last1.id].c;
			last1.a = s1[last1.id].a;
		}
		if(last2.a == 0){
			last2.id++;
			last2.c = s2[last2.id].c;
			last2.a = s2[last2.id].a;
		}
		long long mn = min(last1.a, last2.a);
		if(last1.c != last2.c)ans += mn;
		last1.a -= mn;
		last2.a -= mn;
		i += mn;
		//cout << last1.a << " " << last1.c << " " << last1.id << "\n";
		//cout << last2.a << " " << last2.c << " " << last2.id << "\n";
	}
	cout << ans / 2;
	return 0;
}
