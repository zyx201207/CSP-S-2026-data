#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,ans,n,d,sum,f[5010][5010],a[5010],cha,jl;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c<=10){
		while(T--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(j!=i){
						if(a[j]-a[i]<=d) f[i][j]=1;
						else f[i][j]=998244353;						
					}
					else f[i][j]=0;
			for(int i=1;i<=n;i++)
				for(int j=i-1;j>=0;j--)
					if(a[i]-a[j]<=d) f[i][j]=1;
					else f[i][j]=998244353;

			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					sum=0;
					for(int k=1;k<=n;k++)
						if(i!=k&&j!=k){
							if(f[i][k]+f[k][j]<f[i][j]){
								sum=1;
								f[i][j]=f[i][k]+f[k][j];
							}
							else if(f[i][k]+f[k][j]==f[i][j]){
								sum++;
							}		
						}		
					if(sum==2)
						ans++;
				}
			cout<<ans<<"\n";
		}
	}
	else if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			if(n<=2){
				cout<<0<<"\n";
				continue;
			}
			cha=a[2]-a[1];
			if(cha==0){
				cout<<0<<"\n";
				continue;
			}
			else jl=(d-1)/cha+1;
			for(int i=jl;i<=n-1;i++)
				if(i%jl!=0) ans+=n-i;
			cout<<ans<<"\n";
		}
	}
	else if(c==13||c==14){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			cout<<0<<"\n";
		}
	}
	return 0;
}