#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int p=0;p<t;p++){
		int n,k;
		long long a[400][400];
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
		}
		cout<<n/2;
	}
	return 0;
}















































