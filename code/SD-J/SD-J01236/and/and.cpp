#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,a[N];
int t[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(m==1)
	{
		int maxn=-0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(amxn,a[i]);
		}
		cout<<a[i];
		return 0;
	}
	cout<<a[1];
	return 0;
}
