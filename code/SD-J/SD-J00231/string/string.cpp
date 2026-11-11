#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int n;
	char c;
}a[4000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1;i <= n * 2;i += 2){
		cin >> a[i].n >> a[i].c;
		sum += a[i].n;
	} 
	int sumn = 0;
	if(sum % 2) sum++; 
	for(int i = 1;i <= n * 2;i += 2){
		sumn += a[i].n;
		if(sumn >= sum / 2){
			int tn = a[i].n;
			a[i].n = sumn - sum / 2;
			a[i + 1].c = a[i].c;
			a[i + 1].n = tn - a[i].n;
			break;
		}
	} 
	int ii = 1,iii = 1,jj = 1,jjj = n + 1,ans = 0;
	while(iii < n){
//		cout << ii << ' ' << jj << endl;
		int tiii = a[iii].n;
		if(ii == tiii){
			iii++;
			ii = 0;
		} 
		int tjjj = a[jjj].n;
		if(jj == tjjj){
			jjj++;
			jj = 0;
		} 
		if(a[iii].n == 0) iii++;
		if(a[jjj].n == 0) jjj++;
		if(a[iii].c != a[jjj].c) ans++;
		ii++;jj++;
	}
//	for(int i = 1;i <= n * 2;i++){
//		cout << a[i].n << a[i].c << endl;
//	} 
	cout << ans;
	return 0;
}

