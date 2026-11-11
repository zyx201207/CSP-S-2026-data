#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct stringtype{
	long long num;
	char value;
}num[maxn];
long long n, ans;
vector<stringtype> k1, k2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("string.in", "r", stdin);	
	freopen("string.out", "w", stdout); 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i].num >> num[i].value;
		if(num[i].value == num[i - 1].value){
			num[i - 1].num += num[i].num;
			n--, i--;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int l = 1, r = n; l < r;){
		if(l == r){
			if(num[l].num == 1) break;
			stringtype t;
			t.num = num[l].num / 2;
			t.value = num[l].value;
			k1.push_back(t);
			k2.push_back(t);
			break;
		}
		else{
			if(num[l].num == num[r].num){
				k1.push_back(num[l]);
				k2.push_back(num[r]);
				l++, r--;
			}
			else if(num[l].num > num[r].num){
				k2.push_back(num[r]);
				stringtype t;
				t.num = num[r].num;
				t.value = num[l].value;
				k1.push_back(t);
				num[l].num -= num[r].num;
				r--;
			}
			else{
				k1.push_back(num[l]);
				stringtype t;
				t.num = num[l].num;
				t.value = num[r].value;
				k2.push_back(t);
				num[r].num -= num[l].num;
				l++;
			}
		}
	}
	for(int i = 0; i < k1.size(); i++){
		if(k1[i].value != k2[i].value){
			ans += k1[i].num;
		}
	}
	cout << ans;
	return 0;
}
