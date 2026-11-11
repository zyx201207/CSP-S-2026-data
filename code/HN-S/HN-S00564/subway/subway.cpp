#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l,r,k,w[500005],a[505][1000005],t[505][1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		int ans=w[i];
		ans+=t[3*i][6*i];
		for(int j=ans;j<=n;j++){
			ans+=t[j][j];
			if(i!=1&&j!=1){
				ans+=t[j-1][j];
			}
		}
		ans+=w[3*i];
		cout<<ans<<endl;
	}
	return 0;
}
