#include<bits/stdc++.h>
using namespace std;


const int N = 5e5 +10;

long long n , m;
long long a[N];
long long sub[N];
deque<long long> q;

int main(){
    freopen("crystal.in" ,"r" , stdin);
    freopen("crystal.out" , "w" ,stdout);

	cin >> n >> m;

	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}

	sort(a + 1 , a + n + 1);

	for(int i = 1;i < n;i++){
		sub[i] = a[i + 1] - a[i];
		//cout << sub[i] << endl;
	}

	q.push_back(1);
	long long cnt = 1;
	long long ans = 0;
	long long v = 0;
	for(int i = 2;i <= n;i++){

		v = v + cnt * sub[i - 1];
		while(!q.empty() && v > m){
			v = v - (a[i] - a[q.front()]);
			q.pop_front();
			cnt--;
		}
		q.push_back(i);
		cnt = cnt + 1;
		ans  = max(cnt ,ans);
		//cout << v << " " << cnt <<endl;
	}
	cout << ans << endl;
	return 0;
}
