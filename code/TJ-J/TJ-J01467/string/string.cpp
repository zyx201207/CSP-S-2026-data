#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s;
int n;
long long a[N], tot, tmp, ans;
long long l[N], r[N], lenl, lenr;
long long pl = 1, pr = 1;
char lc[N], rc[N], c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		tot += a[i];
	}
	tmp = tot / 2;
	for(int i = 1; i <= n; i++){
		lc[lenl + 1] = c[i];
		if(tmp - a[i] > 0){
			tmp -= a[i];
			l[++lenl] = a[i];
		}else{
			if(tmp - a[i] == 0){
				l[++lenl] = a[i];
				break;
			}
			l[++lenl] = tmp;
			a[i] -= tmp;
			break; 
		}
	}
//	for(int i = 1; i <= lenl; i++){
//		cout << l[i] << " " << lc[i] << endl; 
//	}
	tmp = tot / 2;
	for(int i = n; i >= 1; i--){
		rc[lenr + 1] = c[i];
		if(tmp - a[i] > 0){
			tmp -= a[i];
			r[++lenr] = a[i];
		}else{
			if(tmp - a[i] == 0){
				r[++lenr] = a[i];
				break;
			}
			r[++lenr] = tmp;
			a[i] -= tmp;
			break; 
		}
	}
//	for(int i = 1; i <= lenr; i++){
//		cout << r[i] << " " << rc[i] << endl; 
//	}
	while(pl <= lenl && pr <= lenr){
		if(l[pl] > r[pr]){
			l[pl] -= r[pr];
			ans += r[pr] * !(lc[pl] == rc[pr]);
			pr++;
		}else if(l[pl] < r[pr]){
			r[pr] -= l[pl];
			ans += l[pl] * !(lc[pl] == rc[pr]);
			pl++;
		}else{
			ans += l[pl] * !(lc[pl] == rc[pr]);
			pl++;
			pr++;
		}
	}
	cout << ans;
	return 0;
}
