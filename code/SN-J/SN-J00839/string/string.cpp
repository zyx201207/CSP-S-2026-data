//姓名:陆坦仪
//考号:SN-J00839
//学校:西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long r,l,ans = 0,cnt = 1,a[N] = {},n;
string s[N] = {};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	//合并相同字符区间 
	for(int i = 1;i <= n;cnt++,i++){
		cin >> a[cnt];
		cin >> s[cnt];
		if(s[cnt] == s[cnt - 1] && cnt > 1){
			a[cnt - 1] += a[cnt];
			a[cnt] = 0,s[cnt] = "";
			cnt--;
		}
	}
	n = cnt - 1;
//	for(int i = 1;i <= n;i++){
//		cout << a[i] <<" -> " << s[i] << '\n';
//	}
//	cout << '\n' << '\n';
	l = 1,r = n;
	while(l <= r){
		if(s[r] != s[l]){
			//消耗 
			if(a[r] > a[l]){
				//aa bbbbbbbbbb aaa
				a[r] -= a[l];
				ans += a[l];
				l++;//l数量干不过r 到下一个区间 
			}else{
				a[l] -= a[r];
				ans += a[r];
				r--;
			}
		}else{
			//消耗 
			if(a[r] > a[l]){
				a[r] -= a[l];
				l++; 
			}else{
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


2
2 a
3 a

3 
2 a
2 b
1 c
*/
