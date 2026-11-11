#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
char c[N];
long long ans;
struct node{
	int st, ed;
	char ch;
}a[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	double m = 0;
	for(int i = 1; i <= n; i ++){
		int tmp_ai;
		cin >> tmp_ai >> c[i];
		m += tmp_ai;
		a[i].st = a[i - 1].ed + 1;
		a[i].ed = a[i].st + tmp_ai - 1;
		a[i].ch = c[i];
	}
	int l, r;l = r = 0;
	if((int)m % 2 == 0){// 偶数 
		l = m / 2;
		r = l + 1;
		m = m / 2.0 + 0.5;
	}else {
		l = m / 2;
		r = m / 2 + 2;
		m = ceil(m / 2.0);
	}
	int fl = 0, fr = 0;
	for(int i = 1; i <= n;i ++){
		if(a[i].st <= l && a[i].ed >= l) l = i, fl = 1;
		if(a[i].st <= r && a[i].ed >= r) r = i, fr = 1;
		if(fl && fr) break;
	}
//	cout << l << " " << r << endl;
	while(l >= 1 && r <= n){
		if(a[l].ch == a[r].ch);
		else {//不相同——>需要变 
			ans += (min(abs(a[l].st - ceil(m)), a[r].ed - floor(m)) - max(ceil(m) - a[l].ed, a[r].st - floor(m)));
			ans ++;
		}
		if(ceil(m) - a[l].st > a[r].ed - floor(m)) r ++;
		else if(ceil(m) - a[l].st < a[r].ed - floor(m)) l --;
		else l --, r ++;
//		cout << l << " " << r << endl;
	}
//	cout<< ceil(m) << " " << floor(m) << endl;
//	cout << a[1].st << " " << a[1].ed << endl;
//	cout << a[3].st << " " << a[3].ed << endl;
	
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}
