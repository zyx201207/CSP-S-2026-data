#include <bits/stdc++.h>
using namespace std;

short c, t;
int n;
long long d;
vector <long long> x, x2;
long long temp;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> temp;
			x.push_back(temp);
		}
		
		long long a;
		int p, sum;
		
		for (int i = 1; i <= n; i++){
			a = 0;
			p = 0;
			sum = 0;
			if (i == 1 or i == 2){
				x2.push_back(1);
				continue;
			}
			while (a < d){
				a += x[i - p] - x[i - p - 1];
				p++;
			}
			for (int j = i - p; j < i; i++){
				sum += x2[j];
			}
			x2.push_back(sum);
		}
		
		for (int i = 1; i <= n; i++){
			for (int j = i + 2; j <= n; j++){
				
			}
		}
		x.clear();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}