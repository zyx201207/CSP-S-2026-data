#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m, ans;
struct Number{
	int num;
	int num1;
	int size;
	string numS;
} numbers[1000000];

int ErJinZhi(int num, int j){
	string s;
	bool check = false;
	int num1 = 0;
	for(int i = 25;i >= 0;i--){
		int l = pow(2, i);
		bool have = num >= l;
		if(have){
			if(!check) check = true;
			s.push_back('1');
			num1++;
			num -= l;
		}
		else
			if(check) s.push_back('0');
	}
	numbers[j].numS = s;
	numbers[j].size = s.size();
	return num1;
}

bool cmp(Number& num1, Number& num2){
	if(num1.size != num2.size)
	    return num1.size > num2.size;
	if(num1.num1 != num2.num1)
	    return num1.num1 > num2.num1;
	return num1.num > num2.num;
}

signed main(){
//	freopen("and.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> numbers[i].num;
		numbers[i].num1 = ErJinZhi(numbers[i].num, i);
	}
	sort(numbers + 1, numbers + 1 + n, cmp);
	for(int i = 1;i <= n - m + 1;i++){
		int num = numbers[i].num;
		for(int j = i + 1;j <= i + m - 1;j++)
			num &= numbers[j].num;
		ans = max(ans, num);
	}
	cout << ans;
	return 0;
}
