#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int cnt=0,n=20;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)==(n/2)){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}