#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e4+10;
int zt[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int a[maxn];
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int m=0;
		int ans=0;
		while(m<n){
			zt[n]=1;
			for(int i=m;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(a[j]<=a[i]+d){
						zt[j]+=zt[i]; 
					}
				}
			}
			for(int i=0;i<n;i++){
				if(zt[i]==2){
					ans++;
				}
			}
			for(int i=0;i<=maxn;i++){
				zt[i]=0;
			}
			m++;
		}
		cout<<ans<<endl;
		for(int i=0;i<=maxn;i++){
			zt[i]=0;
			a[i]=0;
			ans=0;
		}
	}
}
