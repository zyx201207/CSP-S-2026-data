#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

long long a[N], w[N];

long long n, m, q;

int main() {

	freopen("crystal .in", "r", stdin);

	freopen("crystal .out", "w", stdout);

	cin >> n >> m;

	for(int i = 1; i <= n; i ++){

		cin >> a[i];

		q += a[i];

	}

	q = (q + n - 1) / n;

	long long mi, t = a[1];

	if(a[1] - q >= 0){

		mi = a[1] - q;
		

	}

	else{

		mi = -a[1] + q;
		
	}

	for(int i = 2; i <= n; i ++){

		if(a[i] - q >= 0){

			if((a[i] - q) < mi){

				mi = a[i] - q;

				t = a[i];
				
			}

		}

		else{

			if(-a[i] + q < mi){

				mi = -a[i] + q;

				t = a[i];

			}

		}

	}

	long long cnt = 0;
	
	for(int i = 1; i <= n; i ++){
		if(a[i] <= t){
			w[i] = max(a[i], t) - min(a[i], t);
		}
		else{
			w[i] = 0x7f7f7f7f7f7f7f7f;
		}

	}

	sort(w + 1, w + n + 1);
	
	for(int i = 1; i <= n; i ++){
			
		if(m >= w[i]){

			cnt ++;
			
			m -= w[i];
			
		}

	}

	cout << cnt;
	
	
	return 0;

}




