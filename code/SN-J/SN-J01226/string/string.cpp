#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll len = 0, ans = 0;
int n;
int a[200005];
char c[200005];

int rea[200005];
char rec[200005];

int ind = 1,prt = 0;
int reind = 1,reprt = 0;

int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i] >> c[i];
		rea[n+1-i] = a[i];
		rec[n+1-i] = c[i];
		len += a[i];
	}
	
//	for(int i = 1;i <= len/2;++i){
//		++prt;++reprt;
//		if(prt > a[ind]){
//			++ind;
//			prt = 1;
//		}
//		if(reprt > rea[reind]){
//			++reind;
//			reprt = 1;
//		}
//		if(c[ind] != rec[reind])++ans;
//		cout << i << '\n';
//	}
	
	long long i = 0;
	while(1){
//		cerr << i << '\n';
		if(len/2 - i < min(a[ind],rea[reind])){
			if(c[ind] != rec[reind]){
				ans += len/2-i;
			}
//			cerr << "break" << '\n';
			break;
		}
		if(a[ind] == rea[reind]){
			if(c[ind] != rec[reind]){
				ans += a[ind];
			}
			i += a[ind];
			a[ind] = rea[reind] = 0;
			++ind;++reind;
		}
		else if(a[ind] < rea[reind]){
			if(c[ind] != rec[reind]){
				ans += a[ind];
			}
			rea[reind] -= a[ind];
			i += a[ind];
			a[ind] = 0;
			++ind;
		}
		else{
			if(c[ind] != rec[reind]){
				ans += rea[reind];
			}
			a[ind] -= rea[reind];
			i += rea[reind];
			rea[reind] = 0;
			++reind;
		}
//		cout << ans << " ";
	}
	
	cout << ans;
	return 0;
}
