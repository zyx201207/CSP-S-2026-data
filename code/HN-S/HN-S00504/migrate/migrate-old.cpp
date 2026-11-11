#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,t,n,d,a[2145141],ra[2145141],b[2145141],c[2145141],de[2145141];
signed main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin >> C >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			ra[i]=b[i]=c[i]=0;
		}
		for(int i=n;i>=1;--i){
			int l=i,r=n+1;
			while(l+1<r){
				int m=(l+r)/2;
				if(a[m]-a[i]<=d){
					l=m;
				}else{
					r=m;
				}
			}
			ra[i]=l;
		}
		int ans=0;
		for(int i=n;i>=1;--i){
			for(int j=1;j<=n;j++){
				b[j]=c[j]=de[j]=0;
			}
			c[i]=1;
			if(ra[i]!=i){
				for(int j=i+1;j<=ra[i];j++){
					de[j]=1;
					c[j]=1;
				}
			}else{
				continue;
			}
			int R=ra[i]+1,tsr=ra[i],ntsr=R;
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[k]-a[j]>d)break;
					if(de[k]==0||de[k]==de[j]+1){
						de[k]=de[j]+1;
						c[k]+=c[j];
						c[k]=min(c[k],3ll);
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				ans+=(c[j]==2);
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
