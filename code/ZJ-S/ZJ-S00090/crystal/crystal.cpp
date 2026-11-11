#include<bits/stdc++.h>
using namespace std;
long long a[500005];
unordered_map<long long,int> cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,ans = 0;
	long long m,r = 0;
	bool B = true;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		if(i > 2&&a[i]-a[i-1] != a[2]-a[1]){
			B = false;
		}
	}
	if(B){
		for(int i = n;i >= 1;i--){
			if(m >= a[n]-a[i]){
				m -= a[n]-a[i];
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	int pos = n;
	for(int i = n;i >= 1;i--){
		if(m >= a[n]-a[i]){
			m -= a[n]-a[i];
			ans++;
		}else{
			r = m;
			pos = i;
			break;
		}
	}
//	cout<<n<<' '<<ans<<' '<<r<<' '<<pos<<'\n';
	int lst = ans;
	for(int i = n-1;i >= 1;i--){
		if(a[i+1] == a[i]){
			continue;
		}
		int res = lst-cnt[a[i+1]];
		long long nr = (lst-cnt[a[i+1]])*(a[i+1]-a[i])+r;
//		cout<<i<<' '<<res<<' '<<nr<<' ';
		for(int j = min(pos,i);j >= 1;j--){
			if(nr >= a[i]-a[j]){
				nr -= a[i]-a[j];
				res++;
			}else{
				r = nr;
				pos = j;
				break;
			}
		}
//		cout<<res<<' '<<r<<' '<<pos<<'\n';
		ans = max(ans,res);
		lst = res;
	}
	cout<<ans;
	return 0;
}
