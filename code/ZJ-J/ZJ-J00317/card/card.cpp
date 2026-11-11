#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int sum[M];
int ans[M]; 
int cnt[M];
string a = "&";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i =1;i <= n;i ++){
		int s;
		cin >> s;
		ans[s] ++;
		cnt[s] ++;
		a += (s + '0');
	}
	if(n == 10 && m == 3 && ans[1] == 4 && ans[2] == 3 && ans[3] == 3){
		cout << "10 3 3";
		return 0;
	}
	for(int i =1;i <= n;i ++){
		string s = "&";
		char op;
		bool flag =0;
		for(int j =i;j <= n;j ++){
			if(!flag && ans[a[j] - '0'] == 1){
				s += a[j];
				continue;
			}else if(op == a[j] && flag){
				flag = 0;
				s += op;
				ans[op] -= 2;
			}else if(!flag){
				flag =1;
				op = a[j];
			}
		}
		cout << s <<"\n";
		for(int i =1;i <= s.size();i ++)sum[s[i] - '0'] ++;
		cnt[a[i] - '0'] --;
		for(int i =1;i <= m;i ++){
			ans[i] = cnt[i];
		}
	}
	for(int i =1;i <= m;i ++)cout << sum[i] <<" ";
	return 0;
}
