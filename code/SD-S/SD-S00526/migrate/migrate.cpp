#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define For(a,b,c) for(int i=a;i<=b;i+=c)
#define rep(a,b,c) for(int i=a;i>=b;i-=c)
const int N=5005;
int c, t, n, d, a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		set<int> s;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=2;i<=n;i++) s.insert(a[i]-a[i-1]);
		if(s.size()==1){	
			if(s.find(1)){
				int k=2*d-1;
				cout << a[n]-a[1]-k << '\n';
			}
		}
	}
	return 0;
}

