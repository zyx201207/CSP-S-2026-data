#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
int n;
long long a[N], sum[N][27],cnt;
char c[N];
long long k;
int boud(int left,int right){
	int ans = left;
	int l = left,r = right;
	while (l <= r){
		int mid = (l+r)/2;
		if (sum[right][0]-sum[mid-1][0] >= a[left]){
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		sum[i][0] = sum[i-1][0]+a[i];
		for (int j = 1;j <= 26;j++) {
			sum[i][j] = sum[i-1][j];
			if (c[i]-'a'+1 == j) sum[i][j] += a[i];
		}
	}
	int l = 1,r = n;
	while (l < r){
		int mid = boud(l,r);
		long long s = sum[r][0]-sum[mid-1][0], left = s-a[l];;
		long long cs = (sum[r][0]-sum[mid][0])-(sum[r][c[l]-'a'+1]-sum[mid][c[l]-'a'+1]); 
		if (c[mid] != c[l]) cs += a[mid]-left;
		
		a[mid] = left;
		sum[mid][0] = sum[mid-1][0]+a[mid];
		for (int j = 1;j <= 26;j++) {
			sum[mid][j] = sum[mid-1][j];
			if (c[mid]-'a'+1 == j) sum[mid][j] += a[mid];
		}
		cnt+=cs;
	
		
		if (a[mid] == 0) r = mid-1;
		else r = mid;
		l++;
	}
	
	cout << cnt;
	return 0;
}

