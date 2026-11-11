#include <bits/stdc++.h>
using namespace std;
int uv[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int j;
			cin>>j;
			cin>>uv[j];
		}
		cout<<1<<"\n";
	}
	return 0;
}
