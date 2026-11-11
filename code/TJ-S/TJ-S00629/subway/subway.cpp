#include<bits/stdc++.h>
using namespace std;
int a[500005];
int w[500005];
int t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		int c;
		cin>>c;
		cin>>a[i]>>t[i]>>a[i]>>t[i];
		cout<<w[i]+t[i]<<endl; 
	}
	return 0;
} 
