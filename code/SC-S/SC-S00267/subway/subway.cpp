#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e18;
ll n,m,a[500010];
ll s[500010],c[500010],sum=0;
ll man=0,d[500010];
ll fd[500010];
mt19937 rnd(time(0));
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int yu=rnd()%5000001;
		cout<<yu<<endl;
	}
	return 0;
}