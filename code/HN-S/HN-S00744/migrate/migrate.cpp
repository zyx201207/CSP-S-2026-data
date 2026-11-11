#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,m,a[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]>m+a[i]&&a[j]<=2*m+a[i]){
					long long f=0;
					for(int k=i+1;k<j;k++){
						if(a[k]<=m+a[i]&&a[j]<=m+a[k]){
							f++;
						}
					}
					if(f==2){
						ans++;
						int c1=i;
						for(int k=i-1;k>=1;k--){
							if(a[c1]<=m+a[k]&&a[c1+1]>m+a[k]){
								ans++;
								c1=k;
							}
						}
						c1=j;
						for(int k=j+1;k<=n;k++){
							if(a[k]<=m+a[c1]&&a[k]>m+a[c1-1]){
								ans++;
								c1=k;
							}
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//±©Á¦+Ì°ÐÄ£¬12~24 
