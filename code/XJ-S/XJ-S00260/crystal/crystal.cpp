#include<bits/stdc++.h>
using namespace std;
const int N=5e5+12;
int n,q,ans;
long long m,p,a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p+=q*(a[i]-a[i-1]);
		while(p>m){
			p-=a[i]-a[i-q];
			q--;
		}
		ans=max(ans,++q);
	}
	cout << ans;
	return 0;
}
