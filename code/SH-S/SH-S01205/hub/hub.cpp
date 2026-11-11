#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		int a[n][n];
		for(int i=1;i<n;i++){
			int s,e;
			cin>>s>>e;
			a[s][e]=1;
			a[e][s]=1;
		}
		cout<<k-1<<endl;
	}
	return 0;
}
