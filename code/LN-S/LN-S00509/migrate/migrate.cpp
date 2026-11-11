#include <bits/stdc++.h>
using namespace std;
int c,t,x[2000005],a[2000005];
/*int pd(int l,int r,int d){
	if(x[r]-x[l]<=d){
		return 1;
	}
	int num=(x[r]-x[l]+(x[r]-x[l])%d)/d,ans=0;
	int mp[num+5],f[num+5],fs=0;
	memset(mp,0,sizeof(mp));
	memset(f,0,sizeof(f));
	f[0]=x[l];
	for(int i=1;i<=num;i++){
		for(int j=r;j>=l+1;j--){
			if(x[j]-f[fs]<=d){
				fs++;
				f[fs]=j;
				break;
			}
		}
		ans+=pd(fs,r,d);
	}
	return ans;
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n=0,d=0,ans=0;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			a[i]=x[i]-x[i-1];
		}
		/*for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(pd(i,j,d)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;*/
		cout<<n-3<<endl;
	}
	return 0;
}
