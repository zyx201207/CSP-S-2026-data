//Hope you can give me some surprised...
#include<bits/stdc++.h>
using namespace std;
int n,X,JC;
long long a[2100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>JC>>X;
	while(X--){
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(JC>=1 && JC<=10){
			int ans=0;
			for(int i=4;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]>d) break;
//					for(int k=j-1;k>=1;k--){
//						if(a[i]-a[k]>d) break;
						for(int l=j-2;l>=1;l--){
							if(a[l]+d>=a[i]) continue;
							if(a[l]+d<a[j]) continue;
							if(a[l]+d+d<=a[i]) continue;
							
							ans++;
						}
//					}
				}
			}
			cout<<ans<<"\n";
		}
		if(JC==11 || JC==12){
			
			long long MOD=a[2]-a[1];
			if(d<2*MOD) cout<<0<<"\n";
			else cout<<max(n-d/MOD-1,(long long)0)<<"\n";
		}
	}
	return 0;
}
