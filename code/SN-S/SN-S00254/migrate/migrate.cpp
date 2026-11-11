#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005],f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	f[1]=0;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int ans=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int k=2;k<=n;k++){
			for(int p=1;p<=k;p++){
				if(a[p]+d>=a[k]){
					f[k]++;
				}
			}
		}
		for(int k=3;k<=n;k++){
			for(int p=2;p<=k;p++){
				for(int q=1;q<=p;q++){
					if(a[k]==a[p+q]*a[q]){
						ans++;
					}
				}
			}
		}
		
		cout<<ans-1<<endl;
		
	}
	return 0;
}
