#include<bits/stdc++.h>
using namespace std;
int n,k;
long long b[200005];
long long a[200005];
char ch[200005],c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> b[i] >> ch[i];
	for(int i = 1;i <= n;i++){
		int l = i;
		long long sum = 0;
		while(l <= n && ch[l] == ch[l + 1]){
			sum += b[l + 1];
			l++;
		}
		a[++k] = b[i] + sum;
		c[k] = ch[i];
		i = l;
	}
	int l = 1,r = k;
	while(l <= r){
		if(c[l] != c[r]){
			if(a[l] > a[r]){
				ans += a[r];
				a[l] -= a[r--];	
			}else if(a[r] > a[l]){
				ans += a[l];
				a[r] -= a[l++];
			}else{
				ans += a[l];
				l++,r--;
			}
		}else{
			if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}
			else if(a[r] < a[l]){
				a[l] -= a[r];
				r--;	
			}
			else l++,r--;
		}
	}
	cout << ans;
	return 0;
}
