#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200010];
char c[200010];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	
	int l=1, r=n, x=a[l], y=a[r];
	int ans=0;
	
	while(l<r){
		if(c[l]==c[r]){
			if(x==y)x=a[++l], y=a[--r];
			else if(x>y)x-=y, y=a[--r];
			else y-=x, x=a[++l];
		}
		else{
			ans+=min(x,y);
			if(x==y)x=a[++l], y=a[--r];
			else if(x>y)x-=y, y=a[--r];
			else y-=x, x=a[++l];
		}
	}
	
	cout << ans;
	
	return 0;
}
