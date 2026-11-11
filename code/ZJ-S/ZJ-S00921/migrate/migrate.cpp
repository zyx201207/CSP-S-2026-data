#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long a[2000006],w[305][305],ww[305][305],ans[305][305],anss;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--) {
			cin>>n>>d;
			int p=n,pp=0;
			for(int i=1;i<=n;++i) cin>>a[i];
			int dd=a[2]-a[1];
			int anss=0;
			for(int i=1;i<=n;++i){
				if(d<a[i]-a[1]&& a[i]-a[1]<2*d) ++anss;
				else if(a[i]-a[1]>=2*d){
					p=i-1;
					break;
				}else if(d<a[i]-a[1]&& a[i]-a[1]<2*d && a[i-1]-a[1]<=d) pp=i-1;
			}
			cout<<anss*(a[n]-a[p])/dd+anss<<'\n';
		}
	}else if(c<=6) {
		while(t--) {
			memset(ans,0,sizeof ans);
			for(int i=1;i<=300;++i)
			for(int j=1;j<=300;++j)w[i][j]=ww[i][j]=1e18;
			anss=0;
			cin>>n>>d;
			for(int i=1;i<=n;++i){ cin>>a[i];	
			w[i][i]=0;		
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;++j) if(a[j]-a[i]<=d) ww[i][j]=w[i][j]=1;
			}
			for(int k=1;k<=n;++k){
				for(int i=1;i<k;++i){
					for(int j=k+1;j<=n;++j){
						if(w[i][j]>w[i][k]+w[k][j]) w[i][j]=w[i][k]+w[k][j];
					}
				}
			}
			for(int k=1;k<=n;++k){
				for(int i=1;i<k;++i){
					for(int j=k+1;j<=n;++j){
						if(ww[i][j]==ww[i][k]+ww[k][j] && ww[i][j]==w[i][j]) ++ans[i][j];
						if(ww[i][j]>ww[i][k]+ww[k][j]) ww[i][j]=ww[i][k]+ww[k][j];
					}
				}
			}
			for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			if(ans[i][j]==1) anss++;
			cout<<anss<<'\n';
		}
	}
}
