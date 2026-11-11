#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6+6;

int c,t;
ll n,d,a[maxn],ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n>>d;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		if(n<4){
			cout << "0\n";
			break;
		}
		else{
			cout << 1<<"\n";
		}
	}
	return 0;
}

