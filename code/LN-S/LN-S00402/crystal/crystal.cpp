#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int a[N],b[N];
int n,maxn;
long long m;
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin >> n >> m;
	for(int i  = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	b[1] = 0;
	for(int i = 2;i <= n;i++){
		b[i] = b[i-1]+a[1]-a[i];
	}
	b[n+1] = -1e9;
	for(int i = 1;i <= n;i++){
		int r = i,l = n,mid;
		while(true)
		{
			mid = r/2+(l-r)/2;
			if(b[mid]-b[i]-(mid-i)*(a[1]-a[mid]) <= m 
			&& b[mid+1]-b[i]-(mid-i)*(a[1]-a[mid+1]) > m){
				maxn = max(maxn,mid);
				break;
			}
			if(b[mid]-b[i]-(mid-i)*(a[1]-a[mid])  > m){
				l = mid-1;
			}
			if(b[mid+1]-b[i]-(mid-i)*(a[1]-a[mid+1])  <= m){
				r = mid+1;
			}
		}
	}
	cout << maxn;
	return 0;
}
