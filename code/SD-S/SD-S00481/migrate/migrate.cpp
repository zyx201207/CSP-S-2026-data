#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long _,n,m,d,a[N],f[N],g[N][3];
int main(){
	freopen("migrate.in","r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);//cout.tie(0);
	cin>>_>>_;
	while(_--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			g[i][0]=g[i][1]=g[i][2]=0;
		}
		int r=1;
		for(int i = 1;i<=n;i++){
			while(r<n&&a[r+1]-a[i]<=d){
				r++;
			}
			f[i]=r;
//			cout<<i<<" "<<f[i]<<"\n";
		}
		for(int i = n;i>=2;i--){
			if(f[i]==f[i-1]&&f[i-1]==f[i-2]){
				continue;
			}
			if(f[i]>f[i-1]+1){
				g[i][0]+=g[f[i]][0];
				g[i][1]+=g[f[i]][0];
				g[i][2]+=g[f[i]][2];
			}
			else if(f[i]>f[i-1]){
				g[i][0]+=g[f[i]][1];
				g[i][1]+=g[f[i]][1];
				g[i][2]+=g[f[i]][2];
			}
			else {
				g[i][0]+=g[f[i]][2];
			}
			g[i][0]+=f[i-1]-f[i-2];
			g[i][2]+=f[i]-f[i-1];
		}
		long long ans=0;
		for(int i = 1;i<=n;i++){
			if(i<=f[i]-2) 
			ans+=g[f[i]][0];
			else ans+=g[f[i]][1];
//			cout<<g[f[i]][1]<<" ";
//			cout<<ans<<"f\n";
		}
		cout<<ans<<"\n";
	}
}

