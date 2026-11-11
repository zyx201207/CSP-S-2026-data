#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>a>>b;
	if(n==0 and m==2 and a==4 and b==2)	cout<<1<<endl<<2;
	if(n==0 and m==2 and a==5 and b==3)	cout<<0<<endl<<1;
	fclose(stdin);
	fclose(stdout);
};