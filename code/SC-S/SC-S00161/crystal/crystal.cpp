#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int s[N];
int n,m;
int qzh[N];
int maxx = 1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	for (int i  = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s+1,s+n+1);
	
	for(int i = 1;i<=n;i++){
		qzh[i] = s[i]+qzh[i-1];
	}
	for(int i =1;i<=n;i++){
		if(s[i-1]+m<s[i])continue;
		int l = 1,r = i-1,mid;
		while(l<r){
			mid = (l+r)/2;
			if(qzh[i]-qzh[mid-1]+m<s[i]*(i-mid+1)){
				l = mid+1;
			}
			else r = mid;
			//cout<<mid<<"\n";
		}
		maxx = max(maxx,i-mid+1);
	}
	cout<<maxx<<endl;
	return 0;
}