#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int N=2e6+18;
int c,T,n,d,a[N];
struct node{
	int l,r;
}q[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		//pre 
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int l=1,r=1;
		for(int i=1;i<=n;i++){
			while(r+1<=n&&a[i]+d>=a[r+1]){
				r++;
			}
			q[i].l=i;q[i].r=r;
		}
		for(int i=1;i<=n;i++) cout << q[i].l << ' ' << q[i].r << '\n';
		cout << '\n';
	}
	return 0;
}
// Oct31==Dec25?
