#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
const int N = 2e5 + 10;
int n;
struct node{
	int sum;
	char ch;
}a[N],b[N];
signed main(){LYT;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].sum >> a[i].ch;
		b[n - i + 1].sum = a[i].sum; b[n - i + 1].ch = a[i].ch;
	}
	int old = 0,oldw = -1,ans = 0;
	char chold = '#';
	for(int i = 1,j = 1;i <= n && j <= n;){
		if(chold != '#'){
			if(oldw == 0){
				if(old >= b[j].sum){
					if(chold != b[j].ch){
						ans += b[j].sum;
					}
					old -= b[j].sum;
					j++;
				}else{
					if(chold != b[j].ch) ans += old;
					oldw = 1;
					chold = b[j].ch;
					old = b[j].sum - old;
					i++;
				}
			}else{
				if(old >= a[i].sum){
					if(chold != a[i].ch){
						ans += a[i].sum;
					}
					old -= a[i].sum;
					i++;
				}else{
					if(chold != a[i].ch) ans += old;
					oldw = 0;
					chold = a[i].ch;
					old = a[i].sum - old;
					j++;
				}
			}
			continue;
		}
		if(a[i].ch != b[j].ch){
			if(a[i].sum > b[j].sum){
				old = a[i].sum - b[j].sum;
				oldw = 0;
				ans += b[j].sum;
				chold = a[i].ch;
				j++;
			}else if(a[i].sum == b[j].sum) old = 0,oldw = -1,ans += a[i].sum,chold = '#',i++,j++;
			else{
				oldw = 1;
				old = b[j].sum - a[i].sum;
				ans += a[i].sum;
				chold = b[j].ch;
				i++;
			}
		}else{
			if(a[i].sum > b[j].sum){
				old = a[i].sum - b[j].sum;
				oldw = 0;
//				ans += b[j].sum;
				chold = a[i].ch;
				j++;
			}else if(a[i].sum == b[j].sum) old = 0,oldw = -1,chold = '#',i++,j++;
			else{
				oldw = 1;
				old = b[j].sum - a[i].sum;
//				ans += a[i].sum;
				chold = b[j].ch;
				i++;
			}
		}
	}
	cout << ans / 2;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
