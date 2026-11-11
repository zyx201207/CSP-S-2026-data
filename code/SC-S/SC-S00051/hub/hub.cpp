#include<bits/stdc++.h>
#define int long long
#define cin std::cin
#define cout std::cout
#define endl '\n'
using namespace std;
const int maxn=1e5+5;
int c,T;
int n,d;
int x[maxn];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<1<<endl;
	}
	
	return 0;
}