#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//prepare
	unsigned long long n, m;
	cin >> n >> m;
	long long a[n+10];
	for(unsigned long long i = 0; i < n; i++){
		long long b;
		cin >> b;
		a[i] = b;
	}
	sort(a, a + n + 10);
	
	//²î·ÖÊý×é 
	long long s[n+10];
	for(unsigned long long i = 0; i < n; i++){
		if(i == 0)	s[i] = 0;
		else	s[i] = a[i] - a[i-1];
	}
	
	long long maxcount = 0, maxid = 0;
	for(unsigned long long i = 0; i < n; i++){
		long long sum = 0, count = 0;
		for(unsigned long long j = i; j >= 0; j--){
			if(sum + a[i] - a[j] > m)	break;
			else{
				sum += (a[i] - a[j]);
				count++;
			}
		}
		if(count >= maxcount){
			maxcount = count;
			maxid = i;
		}
	}
	cout << maxcount << endl;
	return 0;
} 























