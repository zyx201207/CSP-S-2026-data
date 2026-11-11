#include<bits/stdc++.h>

using namespace std;

struct node{
	long long x;
	char c;
}a[200010];

node b[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
		sum += a[i].x;
	}
	int now = 0;
	char c = 'A';
	for(int i = 1; i <= n; i++){
		if(a[i].c != c){
			b[++now].c = a[i].c;
			b[now].x = a[i].x;
		}else{
			b[now].x += a[i].x;
		}
		c = a[i].c;
	}
	n = now;
	for(int i = 1; i <= n; i++){
		a[i].x = b[i].x;
		a[i].c = b[i].c;
//		cout << a[i].x << " " << a[i].c << "!\n";
	}
	int l = 0;
	int r = 0;
	long long ret = 0;
	if(sum % 2 == 0){
		long long tot = sum / 2;
		long long id1 = 0;
		long long id2 = 0;
		for(int i = 1; i <= n; i++){
			if(tot <= a[i].x){
				l = i;
				id1 = tot;
				break;
			}
			tot -= a[i].x;
		}
		if(a[l].x == id1){
			r = l + 1;
			id2 = 1;
		}else{
			r = l;
			id2 = id1 + 1;
		}
		if(l == r){
			long long num1 = id1;
			long long num2 = a[r].x - id2 + 1;
			if(num1 == num2){
				a[l].x = 0;
				l--;
				r++;
			}else if(num1 < num2){
				a[l].x -= num1 * 2;
				l--;
			}else{
				a[l].x -= num2 * 2;
				r++;
 			}
		}
	}else{
		long long tot = sum / 2 + 1;
		long long id = 0;
		for(int i = 1; i <= n; i++){
			if(tot <= a[i].x){
				l = i;
				id = tot;
				break;
			}
			tot -= a[i].x;
		}
		r = l;
		if(l == r){
			long long num1 = id - 1;
			long long num2 = a[r].x - id;
//			cout << l << " " << r << " ";
//			cout << num1 << " " << num2 << "\n";
			a[l].x--;
			if(num1 == num2){
				a[l].x = 0;
				l--;
				r++;
			}else if(num1 < num2){
				a[l].x -= num1 * 2;
				l--;
			}else{
				a[l].x -= num2 * 2;
				r++;
 			}
		}
	}
	while(1 <= l && r <= n){
		long long num1 = a[l].x;
		long long num2 = a[r].x;
//		if(l == 0 && r == 4){
//			cout << num1 << " " << num2 << a[l].c << " " << a[r].c << "\n";
//			break;
//		}
		
		if(a[l].c == a[r].c){
			if(num1 == num2){
				a[l].x -= num1;
				a[r].x -= num2;
				l--;
				r++;
			}else if(num1 < num2){
				a[l].x -= num1;
				l--;
				a[r].x -= num1;
			}else{
				a[l].x -= num2;
				a[r].x -= num2;
				r++;
			}
		}else{
			if(num1 == num2){
				a[l].x -= num1;
				a[r].x -= num2;
				ret += num1;
				l--;
				r++;
			}else if(num1 < num2){
				a[l].x -= num1;
				l--;
				a[r].x -= num1;
				ret += num1;
			}else{
				a[l].x -= num2;
				a[r].x -= num2;
				r++;
				ret += num2;
			}
		}
	}
	cout << ret;
	
	return 0;
}