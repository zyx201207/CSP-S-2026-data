#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,b[N];
long long a[N],d,k[N],m[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long cnt=0,ans=0;
		cin>>n>>d;
		int h=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			while(a[i]-a[h]>d){
				b[h]=i-1;//可能指向自己 
				h++;
			}
			b[h]=i;
		}
		for(int i=h;i<=n;i++) b[i]=n;
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int tt=1,g=i;
				while(b[g]<j){
					g=b[g];
					tt++;
				}
				cnt=0;
				for(int k=i+1;k<j;k++){
					if(b[i]>=k&&b[k]>=j){
						cnt++;
					}
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}