#include<bits/stdc++.h>
#define ll long long
#define vi void
#define pii pair<int,int>
using namespace std;

int c,t;
mt19937 rd(time(0));

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cout<<rd()%6<<"\n";
	}
	return 0;
}

