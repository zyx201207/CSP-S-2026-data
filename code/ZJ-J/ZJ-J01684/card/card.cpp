#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5+ 10;
int a[N];
int cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cnt[a[i]]++;
	}
	
	for(int i=1;i<=m;++i)cout<<cnt[i]<<" ";
	/*zhi jing wo de OI zhi lu wo de mingzi jiao zuo bolanhailang,ni meng jia you ,wo xian AFO le*/
	return 0;
}
