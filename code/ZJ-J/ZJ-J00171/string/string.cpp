#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long a[100010];
	char s[100010];
	long long l[10010],r[10010];
	char ls[10010],rs[10010];
	long long le=0;
	int k=0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cin >> s[i];
		le += a[i];
	}
	if(le % 2 == 1){
		k = 1;
		le = (le-1)/2;
	}else{
		k = 0;
		le = le/2;
	}
	long long ll = le;
	long long rl = le;
	for(int i = 1;i <= n;i++){
		if(ll >= a[i]){
			ll -= a[i];
			l[i] = a[i];
			ls[i] = s[i];
			a[i] = 0;
		}else{
			a[i] -= ll;
			l[i] = ll;
			ls[i] = s[i];
			ll = 0;
		}
		if(ll == 0 && a[i] != 0){
			if(k == 1){
				a[i]--;
				k++;
			}
			if(rl >= a[i]){
				rl -= a[i];
				r[n-i+1] = a[i];
				rs[n-i+1] = s[i];
				a[i] = 0;
			}else{
				a[i] -= rl;
				r[n-i+1] = rl;
				rs[n-i+1] = s[i];
				rl = 0;
			}
		}
	}
	bool br = true;
	long long ce = 0;
	long long ln = 1;
	long long rn = 1;
	while(br){
		if(ls[ln] == rs[rn]){
			if(l[ln] > r[rn]){
				l[ln] -= r[rn];
				r[rn] = 0;
				rn++;
			}else if(l[ln] == r[rn]){
				l[ln]=0;
				r[rn]=0;
				ln++;
				rn++;
			}else if(l[ln] < r[rn]){
				r[rn] -= l[ln];
				l[ln] = 0;
				ln++;
			}
		}
		else{
			if(l[ln] > r[rn]){
				l[ln] -= r[rn];
				ce+=r[rn];
				r[rn] = 0;
				rn++;
			}else if(l[ln] == r[rn]){
				ce+=r[rn];
				l[ln]=0;
				r[rn]=0;
				ln++;
				rn++;
			}else if(l[ln] < r[rn]){
				r[rn] -= l[ln];
				ce+=l[ln];
				l[ln] = 0;
				ln++;
			}
		}
		if(ln+rn >= n+1){
			br = false;
		}
	}
	cout << ce;
	return 0;
} 
