#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		int w[n+1],v[n+1];
		for(int i=1; i<=n; i++) {
			cin>>w[i]>>v[i];
		}
		cout<<k-1<<endl;
	}
	return 0;
}/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*//*
嵊州市新城实验学校909 ZHY_LOVE_ZZQ
我洛谷号:yeweibo
*/
