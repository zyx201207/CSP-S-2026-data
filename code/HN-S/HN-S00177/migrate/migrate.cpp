#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long x[N],ans,d;
int zt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		if(n<4){
			cout<<0<<"\n";
			continue;
		}
		fill(zt+1,zt+1+n,0);
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n-3;i++){
			if(x[i+2]-x[i]<=d&&x[i+3]-x[i+2]<=d&&x[i+3]-x[i]>d) zt[i]=1;
			else if(x[i+1]-x[i]) zt[i]=-1;
//			cout<<zt[i]<<" ";
		}
		int q=1,sc=1,h;
		bool hf=0;
		for(int i=1;i<=n-3;i++){
			if(zt[i]==1){
				if(hf) ans+=sc*q;
				sc=q;
				q=1; 
				hf=1;
				h=i+3;
				continue;
			} 
			if(zt[i]==-1){
				if(hf) ans+=sc*q;
				hf=0;
				q=1;
			}
			q++;
		}
		if(hf){
			if(zt[n-2]!=-1&&h<n-2){
				q++;
				if(zt[n-1]!=-1) q++;
			}
			else if(zt[n-1]!=-1&&h<n-1) q++; 
			ans+=sc*q;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
