#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Node{
	int n;
	string s;
}note[N];

int main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin >> m;
	for (int i = 1;i <= m;i ++){
		cin >> note[i].n >> note[i].s;
	}
	int l = 1,r = m;
	long long ans = 0;
	while (l < r){
		if (note[l].n <= 0)l ++;
		if (note[r].n <= 0)r --;
		if (note[l].s != note[r].s){
			if (note[l].n > note[r].n){
				ans += note[r].n;
				note[l].n -= note[r].n;
				note[r].n = 0;
				
			}
			else{
				ans += note[l].n;
				note[r].n -= note[l].n;
				note[l].n = 0;
			}
		}else{
			if (note[l].n > note[r].n){
				note[l].n -= note[r].n;
				note[r].n = 0;
			}
			else{
				note[r].n -= note[l].n;
				note[l].n = 0;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
