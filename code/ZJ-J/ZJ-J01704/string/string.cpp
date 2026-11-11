#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long ans;
struct node{
	long long s;
	char c;
}a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		cin >> a[i].s >> a[i].c;
	}
	int l = 1, r = n;
	long long sl = a[l].s, sr = a[r].s;
	while(l <= r){
		if(a[l].c != a[r].c){
			if(sl > sr){
				ans += sr;
				sl -= sr;
				sr = a[--r].s;
				//cout << sl << ' ' << sr;
			}
			else if(sl < sr){
				ans += sl;
				sr -= sl;
				sl = a[++l].s;
			}
			else{
				ans += sl;
				sl = a[++l].s;
				sr = a[--r].s;
			}
		}
		else{
			if(sl > sr){
				sl -= sr;
				sr = a[--r].s;
				
			}
			else if(sr > sl){
				sr -= sl;
				sl = a[++l].s;
			}
			else{
				sr = a[--r].s;
				sl = a[++l].s;
				
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c
Trick||Treat!
*/
