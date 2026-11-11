#include <bits/stdc++.h>
using namespace std;
string exchange(int x){
	string ss, sss;
	int r = 0, q = 0;
	while(x > 0){
		ss[r] = x % 2 + '0';
		x /= 2;
		r ++; 
	}
	for(int i = r - 1;i >= 0;i --){
		sss[q] = ss[i];
		q ++;
	}
	return sss;
}
int change(string y){
	int l = 0;
	int num = 0;
	for(int i = y.size();i >= 0;i --){
		int x = 1;
		if(l = 0){
			num += (y[i] - '0') * 1;
			l ++;
		}
		else{
			for(int i = 1;i <= l;i ++){
				x *= 2;
			}
			num += (y[i] - '0') * x;
			l ++;
		}
	}
	return num;
}
int n, m;
int a[200005];
struct ans{
	string s;
} a1[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("abd.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++){
		a1[i].s = exchange(a[i]);
	}
	string max_s = " ";
	for(int i = 1;i <= n - m;i ++){
		string s4 = a1[i].s;
		string s5;
		for(int j = i + 1;j <= i + m;j ++){
			for(int k = 0;k <= max(s4.size(), a1[j].s.size());k ++){
				if(s4[k] != a1[j].s[k]){
					s5[k] = 0;
				}
				else{
					s5[k] = 1;
				}
			}
		}
		if(s5 >= max_s){
			max_s = s5;
		}
	}
	cout << change(max_s) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
