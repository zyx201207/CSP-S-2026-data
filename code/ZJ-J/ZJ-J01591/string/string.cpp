#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN = 200005;
int a[MAXN];
int a1[MAXN];
char c[MAXN];
char c1[MAXN];
struct Ac{
	int hm;//how many
	char ch;//the char
}cha[MAXN];
//int ch[127], ch1[127];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int totalA = 0; 
	for(int i = 0; i < n; i++){
		cin >> cha[i].hm >> cha[i].ch;
		totalA += cha[i].hm;
	}
	int half = totalA / 2;
	int sum = 0;
	int maxi = 0;
{	
	//total letters in 'a'
//	for(int i = 0; i < n; i++) {
//		sum += a[i];
//		if(sum >= half){
//			sum -= a[i];
//			ch[c[i]] += half - sum;
//			break;
//		}
//		ch[c[i]] += a[i];
//	}
	
//	int half1 = (half % 2 == 0) ? half + 1 : half + 2;
//	sum = 0;
//	for(int i = half1; i < n; i++){
//		sum += a[i];
//		ch[c[i]] += a[i];
//	}
}
	for(int i = 0; i < n; i++) {
		sum += cha[i].hm;
		if(sum >= half){
			sum -= cha[i].hm;
			a[i] = half - cha[i].hm;
			c[i] = cha[i].ch;
			maxi = i;
			break;
		}
		a[i] = cha[i].hm;
		c[i] = cha[i].ch;
	}
	for(int i = n - 1, j = maxi; j > 0; i--, j--){
		a1[j] = cha[i].hm;
		c1[j] = cha[i].ch;
	}
	//when j == 0
	a1[0] = cha[maxi].hm - a[maxi];
	c1[0] = cha[maxi].ch;
	// 1
	int cnt = 0;
	for(int i = 0; i < maxi; i++){
		if(c[i] != c1[i]) cnt += a[i];
		if(a[i] != a1[i]) cnt += min(a[i], a1[i]);
	}
	int cnt2 = 0;
	for(int i = 0; i < maxi; i++){
		if(c[i] != c1[i]) cnt += a1[i];
		if(a[i] != a1[i]) cnt += min(a[i], a1[i]);
	}
	cout << min(cnt,cnt2);
	return 0;
}
