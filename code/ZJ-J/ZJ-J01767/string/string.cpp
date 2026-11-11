#include<bits/stdc++.h>
using namespace std;
#define For(i ,x ,y) for(int i = x; i <= y; ++ i)
#define Down(i ,x ,y) for(int i = x; i >= y; -- i)
#define int long long
int T ,a[210000] ,Ans ,Sum ,j;
char ch[210000];
string S;
bool p;
signed main(){
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	For(i ,1 ,T){
		cin >> a[i] >> ch[i];
		Ans += a[i];
		For(j ,1 ,a[i]) S += ch[i];
	}
	p = true;
	For(i ,2 ,T) {
		if(a[i] != a[i - 1]){
			p = false;
			break;
		}
	}
	if(p == true){
		cout << 0;
		return 0;
	}
	For(i ,1 ,(Ans + 1) / 2){
		j = Ans - i + 1;
		if(S[i - 1] == S[j - 1]) continue;
		else Sum ++;
	}
	cout << Sum;
	return 0;
}