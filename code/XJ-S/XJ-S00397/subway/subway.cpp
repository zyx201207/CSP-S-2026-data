#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int c,n,m,d,q,w[N],a[N],t[N],k,x1,r1,x2,r2,ans1,ans2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			ans1+=t[j];
			ans2+=a[j];
		}
	}
	cin>>x1>>r1>>x2>>r2;
	for(int i=1;i<=q;i++) cout<<ans1<<endl; 
	return 0;
}
