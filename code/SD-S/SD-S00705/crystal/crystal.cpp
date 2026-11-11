#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5+5;
int n,Ans;
i64 s[N],a[N],m;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) s[i] = s[i-1] + a[i];
	for(int i = 1;i<=n;i++){
		int l = 1,r = i,ans = 0;
		while(l<=r){
			int mid = (l+r)>>1;
			int len = i - mid +1;
			i64 sum = len*a[i],summ = s[i]-s[mid-1];
			if(sum - summ <= m) ans = len, r = mid-1;
			else l = mid+1;
		}
		Ans = max(Ans,ans);
	}
	cout<<Ans<<"\n";
	return 0;
}
