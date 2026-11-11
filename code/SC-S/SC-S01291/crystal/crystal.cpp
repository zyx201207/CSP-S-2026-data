#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
long long check(){
	int sum,cnt=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			sum+=(a[i]==a[j]);
		}
		cnt=max(sum,cnt);
	}
	return cnt;
}
void crr(){
	for(int i=1;i<=n;i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}
void solve(int p,int sum){
	if(sum==m||p>n){
		ans=max(check(),ans);
		return;
	}
	for(int i=p;i<=n;i++){
		a[i]++;
		solve(i,sum+1);
		a[i]--;
	}
}
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	solve(1,0);
	cout << ans;
	return 0;
} 