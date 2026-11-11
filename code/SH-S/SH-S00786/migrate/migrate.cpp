#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=2e6+10;
int c,t,n,m,a[Maxn],f[Maxn],b[Maxn],k[Maxn],sum[Maxn],i,j;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			for(i=1;i<=n;i++) f[i]=b[i]=k[i]=sum[i]=0;
			j=n;
			for(i=n;i>=1;i--){
				while(a[j]-a[i]>m) j--;
				f[i]=j;
			} 
			j=1;
			for(i=1;i<=n;i++){
				while(a[i]-a[j]>m) j++;
				b[i]=j;
			}
			for(i=n;i>=b[n];i--) k[i]=1;
			j=b[n];
			for(i=b[n]-1;i>=1;i--){
				if(i<b[j]) j=b[j];
				for(int p=j;p<=f[i];p++){
					k[i]+=k[p];
					if(k[i]>2) break;
				}
				if(k[i]==2) ans++;
				sum[n-i+1]=ans;
			}
			ans=0;
			for(i=1;i<=n;i++) ans+=sum[i];
		}
		else if(c==13||c==14){
			for(i=1;i<=n;i++) f[i]=b[i]=k[i]=0;
			j=n;
			for(i=n;i>=1;i--){
				while(a[j]-a[i]>m) j--;
				f[i]=j;
			} 
			for(i=1;i<=n;i++){
				if(f[i]<=2||f[i]==n||f[i]-2<i) continue;
				ans+=f[f[i]-1]-f[f[i]-2];
			}
		}
		else{
			while(n>2){
				for(i=1;i<=n;i++) f[i]=b[i]=k[i]=0;
				j=n;
				for(i=n;i>=1;i--){
					while(a[j]-a[i]>m) j--;
					f[i]=j;
				} 
				j=1;
				for(i=1;i<=n;i++){
					while(a[i]-a[j]>m) j++;
					b[i]=j;
				}
				for(i=n;i>=b[n];i--) k[i]=1;
				j=b[n];
				for(i=b[n]-1;i>=1;i--){
					if(i<b[j]) j=b[j];
					for(int p=j;p<=f[i];p++){
						k[i]+=k[p];
						if(k[i]>2) break;
					}
					if(k[i]==2) ans++;
				}
				n--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
