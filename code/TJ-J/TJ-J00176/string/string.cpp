#include <bits/stdc++.h>
using namespace std;
string s[200005], c, s2[200005];
long long n, a, cnt, sum;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a >> c;
		for(int j=0; j<=a-1; ++j){
			s[cnt++]=c;
		}
	}
	for(int i=0; i<=cnt; ++i){
		s2[i]=s[i];
	}
	reverse(s, s+cnt); //reverse最好用的一集 
	for(int i=1; i<=n; ++i){
		if(s[i]!=s2[i]){
			sum++;
		}
	}
	
	cout << sum;
	return 0;
}
//这么做好像只有8个测试点 就是8*4=32， 两千以上直接炸了 [思考] 132好像不是很保险 
//2026.10.31 10:22:40 我在位于宇宙银河系太阳系地球亚欧大陆亚洲东亚中国天津市南开区天津大学六里台校区综合实验楼3层304想出了怎么把字符串拼一起 我简直就是天才 巴哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈 
