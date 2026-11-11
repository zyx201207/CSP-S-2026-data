#include<bits/stdc++.h>
using namespace std;

struct cpp{
	int l,r;
	int v;
}t[200010];
int l = 1;
int a[200010];
int n,m;
void inserts(string s,int fa){
	char c = s[0];
	string k = "";
	for(int i = 1;i < (int)s.size();i++){
		k += s[i];
	}
	if(c == '1'){
		if(t[fa].l == 0){
			t[fa].l = ++l;
		}
		if(k.size() == 0){
			t[t[fa].l].v++;
		}else{
			inserts(k,t[fa].l);
		}
	}
	if(c == '0'){
		if(t[fa].r == 0){
			t[fa].r = ++l;
		}
		if(k.size() == 0){
			t[t[fa].r].v++;
		}else{
			inserts(k,t[fa].r);
		}
	}
}
string ans = "111111111111111111111111111111";
bool b;
void dfs(int x,string s){
	if(b){
		return ;
	}
	if(t[x].l != 0){
		dfs(t[x].l,s + '1');
	}
	if(t[x].r != 0){
		dfs(t[x].r,s + '0');
	}
	if(t[x].v != 0){
		m -= t[x].v;
		string ans2;
		int l = ans.size();
		for(int i = l - s.size() + 1;i <= l;i++){
			ans2[i - l + s.size()] = ans[i];
		}
		for(int i = 0;i < (int)s.size();i++){
			if(ans2[i] != s[i]){
				ans2[i] = 0;
			}
		}
		ans = ans2;
		//cout << ans << ' ';
		if(m <= 0){
			b = 1;
			return ;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		string s;
		while(a[i]){
			s += a[i] % 2 + '0';
			a[i] /= 2;
		}
		int l = s.size() - 1;
		for(int i = 0;i <= l / 2;i++){
			swap(s[i],s[l - i]);
		}
		if(s == "1"){
			t[1].v++;
		}
		string k = "";
		for(int i = 1;i < (int)s.size();i++){
			k += s[i];
		}
		inserts(k,1);
	}
	string s = "1";
	dfs(1,s);
	if(m > 0){
		cout << 0;
		return 0;
	}
	int k = 0;
	for(int i = 0;i < (int)ans.size();i++){
		if(ans[i] == 0 && k == 0){
		}else{
			k = 1;
			cout << ans[i];
		}
	}
	cout << ans;
}
