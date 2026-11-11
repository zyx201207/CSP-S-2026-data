#include <bits/stdc++.h>
using namespace std;

long long a[5000010];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	/*
	int n;
	long long m;
	cin >> n >> m;
	
	for(int i = 0;i < n;i++)	cin >> a[i];
	
	sort(a,a + n);
	
	int Max = 1;
	for(int i = 1;i < n;i++){
		long long tmp = m;
		
		int cnt = 0;
		for(int j = i - 1;j >= 0 && tmp - a[i] + a[j] >= 0;j--){
			tmp -= a[i] - a[j],cnt++;
		}
		
		Max = max(Max,cnt + 1);
	}
	
	cout << Max;*/
	
	char cnt = ' ';
	while(true)	cout << char(cnt += 1);
	return 0;
} 
