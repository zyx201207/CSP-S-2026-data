#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int a[N];
char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//string
	int n; cin >>n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >>ch[i];
		sum+=a[i];
	}
	int l=1,r=n;
	int ans = 0;
	while(l < r){
		if(ch[l] != ch[r])
			ans+=min(a[l],a[r]);
		//ÌøÒ»¸ñ
		if(a[l] < a[r]) a[r]-=a[l++];
		else if(a[l] > a[r]) a[l]-=a[r--];
		else if(a[l] == a[r]) l++,r--;
	}
	cout <<ans;
}
