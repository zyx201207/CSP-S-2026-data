#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
struct node{
	long long k;
	long long a[2505],t[2505]; 
}v[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v[i].k;
		for(int j=1;j<=v[i].k;j++){
			cin>>v[i].a[i]>>v[i].t[i];
		}
	}
	while(q--){
		long long l,r;
		cin>>l>>r;
		cout<<w[l]+w[r]<<endl;
	}
	return 0;
} 