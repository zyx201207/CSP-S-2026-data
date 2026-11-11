#include<bits/stdc++.h>
using namespace std;
int n;
char s;
vector<char> ss;
struct {
	long long num;
	char ch;
} a[200005];
long long l,ans;
int main(){  
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].ch;
		l += a[i].num;
		for(int j = 1;j <= a[i].num;j++){
			ss.push_back(a[i].ch);
		}
	}
	for(int i = 0;i < l / 2;i++){
		if(ss[i] != ss[l - i - 1]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
