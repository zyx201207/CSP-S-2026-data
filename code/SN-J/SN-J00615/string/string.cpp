#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n;
string s;
int a[N];
char c[N];
int ans = 0,res = 0;
bool id = 0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l = 1,r = n;
	while(l < r){
		int x = a[l];
		int y = a[r];
		if(res != 0){
			if(id == 0) a[r] -= res;
			else a[l] -= res;
			res = 0;
		}
		if(c[l] == c[r]){
			res = abs(x-y);
			if(a[l] == a[r]){
				if(c[l] == c[r]){
					l++;
					r--;
					continue;
				}
				else{
					ans += a[r];
					l++;
					r--;
				}
			}
			else if(a[l] > a[r]){
				r--;
				while((res >= a[r]) && (l < r)){
					res -= a[r];
					if(c[l] != c[r]) ans += a[r];
					r--;
				}
				if(res != 0){
					id = 0;
					if(l >= r) continue; 
					if(c[l] != c[r]) ans += res;
				}
				l++; 
			}
			else{
				l++;
				while((res >= a[l]) && (l < r)){
					res -= a[l];
					if(c[l] != c[r]) ans += a[l];
					l++;
				}
				if(res != 0){
					id = 1;
					if(l >= r) continue; 
					if(c[l] != c[r]) ans += res;
				}
				r--;
			}
		}
		else{
			res = abs(x-y); 
			if(a[l] == a[r]){
				if(c[l] == c[r]){
					l++;
					r--;
					continue;
				}
				else{
					ans += a[r];
					l++;
					r--;
				}
			}
			else if(a[l] > a[r]){
				ans += a[r]; 
				r--;
				while((res >= a[r]) && (l < r)){
					res -= a[r];
					if(c[l] != c[r]) ans += a[r];
					r--;
				}
				if(res != 0){
					id = 0;
					if(l >= r){
						continue;
					}
					if(c[l] != c[r]) ans += res;
				}
				l++; 
			}
			else{
				ans += a[l];
				l++;
				while((res >= a[l]) && (l < r)){
					res -= a[l];
					if(c[l] != c[r]) ans += a[l];
					l++;
				}
				if(res != 0){
					id = 1;
					if(l >= r) continue; 
					if(c[l] != c[r]) ans += res;
				} 	
				r--; 
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
