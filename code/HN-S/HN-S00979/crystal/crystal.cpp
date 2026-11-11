#include <bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
vector<long long> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if (n==1){
		cout << 0;
		return 0;
	}
	for (int i=0;i<n;i++){
		long long x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for (int i=1;i<n;i++){
		long long cnt=1;
		long long t=m;
		for (int j=i-1;j>=0;j--){
			long long diff=(a[i]-a[j]);
			if (t>diff){
				t-=diff;
				cnt++;
			}else{
				break;
			}
		}
		ans=max(cnt,ans);
	}
	cout << ans;
	return 0; 
}
