
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[100000],k,a[10000],t[10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	vector <int> v;
	
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++) cin>>a[i]>>t[i];
	}
	
	return 0;
}
