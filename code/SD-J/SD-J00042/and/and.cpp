#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
string s[200005];
string jz(int x){
	string cur = "";
	while(x){
		cur += (char)(x % 2 + '0');
		x /= 2;
	}
	string res = "";
	int len = cur.size();
	for(int i = len - 1;i >= 0;i--) res += cur[i];
	return cur;
}
long long zh(string x,int k){
	long long ans = 0;
	int len = x.size();
	if(k == 1)
		for(int i = 0,k = 1;i < len;i++,k *= 2)
			ans += k * (x[i] - '0');
	else 
		for(int i = len - 1,k = 1;i >= 0;i--,k *= 2)
			ans += k * (x[i] - '0');
	return ans;
}
string res;
bool f[200005];
long long ans;
int maxl = 0;
int cnt[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i]; 
	sort(a + 1,a + n + 1,greater<int>());
	for(int i =1;i <= n;i++){
		s[i] = jz(a[i]);
		int len = s[i].size();
	}
	for(int i = 1;i <= n;i++){
		int len = s[i].size(),t = 0;
		for(char ch : s[i]){
			if(ch == '1') 
				cnt[t]++;
			t++;
		}
		string res = "";
		for(int j = 0;j < len;j++){
			if(s[i][j] == '1'){
				if(cnt[j] >= m) res += '1';
				else res += '0';
			}else res += '0';
		}
		ans = max(ans,zh(res,1));
	}
	cout << ans;
	return 0;
}
/*
for(int i = 0;i < maxl;i++){
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			if(f[j]) continue;
			//cout << s[j][i] << ' ';
			if(s[j][i] == '1')
				cnt++;
			else f[j] = 1;
		} 
		//cout << cnt << endl;
		if(cnt >= m) res += '1';
		else res += '0';
	}
	ans1 = zh(res,1),res = "";
	memset(f,0,sizeof f);
	for(int i = maxl - 1;i >= 0;i--){
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			if(f[j]) continue;
			//cout << s[j][i] << ' ';
			if(s[j][i] == '1')
				cnt++;
			else f[j] = 1;
		} 
		//cout << cnt << endl;
		if(cnt >= m) res += '1';
		else res += '0';
	}
	ans2 = zh(res,2);
	cout << ans1 << ' ' << ans2 << endl;
	cout << max(ans1,ans2); 
*/
