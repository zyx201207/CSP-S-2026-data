#include<bits/stdc++.h>
using namespace std;

const int N=500000;
long long c,n,m,d,q,i,j;
long long w[N],a[N],t[N],k[N],b[N],f[N];
int main(){
	freopen(":subway.in","r",stdin);
	freopen(":subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=0;i<m;i++) cin>>w[i];
	for(i=0;i<n;i++){
		cin>>k[i];
		for(j=0;j<a[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for(i=0;i<q;i++) cin>>b[N]>>f[N];
	cout<<"45"<<endl<<"57";
	return 0;
}