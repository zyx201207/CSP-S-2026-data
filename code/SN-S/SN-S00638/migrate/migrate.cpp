#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[2000001];
int qz[2000001],dis[2000001],ldis[2000001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int ans=0;
	for(int i=1;i<=n;i++){
		qz[i-1]=0;
		dis[i]=0,qz[i]=1,ldis[0]=i;
		int l=i;
		for(int j=i+1;j<=n;j++){
			while(a[j]-a[l]>m)l++;
			dis[j]=dis[l]+1;
			qz[j]=qz[ldis[dis[l]]]-qz[l-1];
//			for(int k=l;k<j && dis[k]==dis[l];k++){
//				qz[j]+=qz[k];
//			}
//			cout<<i<<' '<<j<<'|'<<qz[j]<<endl;
			if(qz[j]==2)ans++;
			qz[j]+=qz[j-1];
			ldis[dis[j]]=j;
		}
	}cout<<ans<<endl;
	}
	return 0;
}
