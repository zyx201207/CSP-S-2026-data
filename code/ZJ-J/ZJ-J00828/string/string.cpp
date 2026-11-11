#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct node{
	long long num;
	char c;
} a[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].num >> a[i].c;
	}
	int i = 1;
	int j = n;
	long long ans = 0;
	while(i < j){
		if(a[i].c != a[j].c){
			ans += min(a[i].num, a[j].num);
		}
		long long w = min(a[i].num, a[j].num);
		a[i].num -= w;
		a[j].num -= w;
		if(a[i].num == 0){
			i++;
		}
		if(a[j].num == 0){
			j--;
		}
	}
	cout << ans;
	return 0;
}
