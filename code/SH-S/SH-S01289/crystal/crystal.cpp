# include <iostream>
# include <algorithm>
# include <queue>
# include <vector>
# define ll long long
# define MAXN 500010
using namespace std;
int n;
ll m;
ll cnt;
ll ans, tmp;
ll a[MAXN],b[MAXN];
ll diff[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++) b[i] = 1;
	for(int i = 1; i < n; i++) diff[i] = a[i + 1] - a[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) b[j] = 1;
		tmp = 1;
		cnt = 0;
		for(int j = i; j <= n; j++){
			cnt += b[j] * diff[j];
			tmp++;
			b[j + 1] += b[j];
			//cout<<tmp<<"\n";
			if(cnt > m){
				ans = max(ans,tmp-1);
				//cout<<"ans::"<<ans<<"\n";
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
