#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5 + 101;
int n,m,ans,cnt,maxn,a[N],b[N];
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<n;i++)
		b[i] = a[i+1] - a[i];
	int l=1,r=1;
	while(1){
		ans += b[r++];
		cnt++;
		while(ans > m){
			ans -= b[l];
			cnt--;
			l++;
			f = 1;
		}
		if(f==1 && maxn<cnt){
			maxn = cnt;
		}
		if(r==n)
			break;
	}
	cout << maxn+1;
	return 0;
}
/*
Oct31==Dec25?
*/
