#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s = 0 , w = 1;
	char ch = getchar();
	while('0' > ch || '9' < ch){
		if(ch == '-'){
			w *= -1;
		}
		ch = getchar();
	}
	while('0' <= ch && '9' >= ch){
		s = (s << 1) + (s << 3) + (ch ^ 48);
		ch = getchar();
	}
	return s * w;
}
int a[500005];
int n , m;
bool check(int k){
	int ans = 0;
	for(int i  = 1;i <= k;i++){
		ans += a[k] - a[i]; 
	}
	if(ans <= m) return 1;
	return 0; 
} 
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	/* DONE (#1#): 解除注释 */
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	n = read();
	m = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
	} 
	sort(a + 1 , a + n + 1);
	int l = 1  , r = n;
	while(l + 1 < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}//check 判断mid是否满足 ： m次操作内能使mid块石头均变成a[mid]块；  
//		cout << l << " " << r << " " << mid << " " << check(mid) << endl;
	}//log n
	cout << l;
	//二分答案 
}
