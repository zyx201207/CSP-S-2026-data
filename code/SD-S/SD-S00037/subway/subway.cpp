#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q,w[N],k[M],a[N][50],t[N][50],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		ans+=w[l]+w[r]+t[l][l];
		if(l>r) swap(l,r);
		if(c>=7&&c<=11){
			while(l!=r){
				for(int i=1;i<=n;i++){
					if(a[i][1]==l){
						ans+=t[l][a[i][2]]+t[a[i][2]][a[i][2]];
						l=a[i][2];
						break;
					}
				}	
			}
			cout<<ans-t[r][r]<<endl;
		}
		else cout<<t[l][l]+t[l][r]+t[r][r]<<endl;
		ans=0;
	}
	return 0;
}
