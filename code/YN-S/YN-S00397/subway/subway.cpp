#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, t[100005], k,sta[100005],s[100005],be,end; //测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
strcut node{
	long long n,v;
}
vector <node> q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		cin>>k;
		for (int i = 1; i <= k; i++) {
			cin>>sta[i]>>s[i];
		}
	}
	for(int i=1;i<=q;i++){
		long long sum=0,T=0;
		cin>>be>>end;
		for(int i=be;i<=end;i++){
			T+=s[i];
		}
		sum+=t[be] +T+ t[end];
		cout<<sum<<endl;
		
	}
	return 0;
}