#include<bits/stdc++.h>
using namespace std;
long long a[500009],s[500009],x[500009];
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long pre;
	cin>>n>>m;
	cin>>pre;
	a[0] = s[0] = 0;
	for(int i = 0;i < n;i++){
		cin>>x[i];
	}
	sort(x,x + n);
	for(int i = 1;i < n;i++){
		a[i] = x[i] - x[i - 1];
		s[i] = s[i - 1] + a[i];
	}
	long long ans = 1,now = 1,cost = 0;
	for(int i = 0,j = 1;i < n and j < n;j++){
		while((a[j] * now + cost) > m and i < j){
			//cout<<i<<' '<<j<<' '<<cost<<' '<<a[j] * now<<' '<<now<<endl;
			cost -= (s[j - 1] - s[i]);
			now--;i++;
		}
		cost += (a[j] * now);
		now++;
		ans = max(ans,now);
	}
	cout<<ans;
	return 0;
}
