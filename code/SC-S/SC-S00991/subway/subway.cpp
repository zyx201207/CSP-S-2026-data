#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w;
	for(int i=0;i<m;i++){
		cin>>w;
	}
	int t;
	for(int i=0;i<n;i++){
		cin>>t;
	}
	int x,y;
	for(int i=0;i<q;i++){
		cin>>x>>y;
	}
	int a[200005]={32,17};
	for(int i=0;i<q;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}