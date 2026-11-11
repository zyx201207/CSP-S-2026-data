#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false),cout.tie(false);
	srand(time(0));
	long long int t;cin>>t;
	for(int i=1;i<=t;i++){
		int n,m;cin>>n>>m;
		for(int j=1;j<=n;j++){
			int a;cin>>a;
		}
		cout<<rand()%n;
	}
	return 0;
}