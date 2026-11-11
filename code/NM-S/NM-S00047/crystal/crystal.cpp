#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	int a[N];
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int sum=0,num=0;
	int mm=m;
	for(int i=n;i>=1;--i){
		sum=1;
		m=mm;
		for(int j=i-1;j>=1;--j){
			if(a[i]-a[j]<=m){
				m=m-(a[i]-a[j]);
				++sum;
			}
		}
		if(i==n){
			num=sum;
		}	
		else{
			num=max(num,sum);
		}
	}
	cout << num;
	return 0;
}
