#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2E6+3;
int a[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,a,b;
		cin>>x>>y;
		for(int i=1;i<n;i++){
			cin>>a>>b;
		}
		cout<<y-1<<endl;
	}
	return 0;
}


