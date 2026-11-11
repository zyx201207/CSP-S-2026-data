#include<bits/stdc++.h>
using namespace std;
int a[200005],pre[200005];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while (t--){
		int n,d;
		
		cin >>n>>d;
//		memset(pre,0,sizeof(pre));
//		memset(a,0,sizeof(a));
		int ans=0;
		for (int i=1;i<=n;i++){
			cin >>a[i];
			pre[i]=pre[i-1]+a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+3;j<=n;j++){
				int cnt=0;
				if (a[j]-a[i]<=d) continue;
				
				for (int k=i+1;k<=j-1;k++){
					if (a[k]-a[i]<=d && a[j]-a[k]<=d){
						cnt++;
					}
					
//					cout <<i<<" "<<j<<" "<<k<<" "<<a[k]-a[i]<<" "<<a[j]-a[k]<<endl;
				}
				
				if (cnt==2){
					ans++;
				}
			}
		}
		cout <<ans<<endl;
	}
}

