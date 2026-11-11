#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
int n;
long long m,a[M],s[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		s[i] = s[i-1]+(i-1)*(a[i]-a[i-1]);
	int ans=0;
	if(n<=5000){
		for(int i=1; i<=n; i++){
			long long t = m;
			int j=i-1,tp=1;
			while(a[i]-a[j]<=t && j>0){
				t-=(a[i]-a[j]);
				tp++;
				j--;
				if(tp==i) break;
			}
			ans = max(ans,tp);
		}
		cout << ans;
	}else{
		for(int i=1; i<=n; i++){
			int l=1,r=i;
			while(l<r){
				int mid = (l+r)>>1;
				if(s[i]-s[mid] <= m){
					r = mid;
				}else{
					l = mid+1;
				}
			}
			ans = max(ans,i-l+1);
		}
		cout << ans;
	}
	return 0;
}