#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,k;
vector<int> a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
