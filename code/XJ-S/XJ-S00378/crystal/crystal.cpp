//crystal.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long m;
long long p[500005];//ÄÜÁ¿
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+1+n);
	long long l = n, r = n, diffsum = 0, maxlen = 1;
	while(l >= 1 && r >= 1){
		if(diffsum <= m){
			maxlen = max(r - l + 1, maxlen);
			l--;
			diffsum += p[r] - p[l];
		}
		else{
			maxlen = max(r - l, maxlen);
			r--;
			diffsum -= (p[r + 1] - p[r]) * (r - l + 1);
		}
	}
	cout << maxlen;
	return 0;
} 
