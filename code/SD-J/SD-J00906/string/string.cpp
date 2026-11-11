#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n;
int ans;
struct node{
	int a;
	char c;
}; 
node s[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> s[i].a >> s[i].c;
	}
	int idl = 1;
	int l = s[1].a;
	char l2 = s[1].c;
	int idr = n;
	int r = s[n].a;
	char r2 = s[n].c;
//	cout << n << endl;
	while(idl < idr){
		int minn = min(l, r);
//		cout << idl << " " << idr << " " << l << " " << r << " " << l2 << " " << r2 << endl; 
		if(minn == l){
			//×ó±ßĞ¡£¬ÓÒ±ß´ó
			if(l2 == r2){
				
			}else{
				ans += minn;
			}
			//ÓÒ±ß¼õÈ¥
			r -= minn;
			if(r == 0){
				//Ã»ÁË
				idr--;
				r = s[idr].a;
				r2 = s[idr].c; 
			} 
			idl++;
			l = s[idl].a;
			l2 = s[idl].c;
		}else{
			if(l2 == r2){
				
			}else{
				ans += minn;
			}
			l -= minn;
			if(l == 0){
				idl++;
				l = s[idl].a;
				l2 = s[idl].c;
			}
			idr--;
			r = s[idr].a;
			r2 = s[idr].c;
		}
	}
	cout << ans;
	return 0;
} 


