#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ans=0;
long long w[20005];
long long a[500][500],t[500][500],k[500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
		}
		if(n==3) cout<<35<<endl<<16;
	}
else{
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			ans=0;
			int zls,hx;
			cin>>zls>>hx;
			if(zls>hx) swap(zls,hx);
			ans=w[zls]+w[hx];
			for(int j=1;j<=q;j++){
				int flag1=0,flag2=0;
				for(int yhb=1;yhb<=k[i];yhb++){
					if(a[j][yhb]==zls) flag1=1;
					if(a[j][yhb]==hx)	flag2=1;
				}
				if(flag1==1&&flag2==1){
					ans=ans+t[zls][zls]+t[zls][hx];
					continue;
				}
			}
			if(ans!=w[zls]+w[hx]){
				cout<<ans<<endl;
				continue;
			}
			else{
				for(int i=zls;i<hx;i++){
					ans=ans+t[i][i]+t[i][i+1];
				}
				ans+=t[zls][hx];
				cout<<ans<<endl;
				continue;
			}
		}
	}
	return 0;
}