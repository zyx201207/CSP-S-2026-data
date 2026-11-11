#include<bits/stdc++.h>

using namespace std;


long long m;
long long n;
long long c;
long long a[5000001];
long long w[5000001];
long long b[5000001];
long long num;
long long p;

int main(){
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a + 1,a + n + 1);
		for(int i = 1;i < n;i++){
			w[i] = a[i + 1] - a[i];
			if(a[i + 1] < 0 && a[i] < 0){
				w[i] = a[i + 1] + a[i];
				w[i] = w[i] * -1; 
			}
		}
		for(int i = 0;i < n;i++){
			num = num + w[i];
			if(num > m){
				break;
			}
			p++;
		}
		cout << p << endl;
		return 0;
	}


