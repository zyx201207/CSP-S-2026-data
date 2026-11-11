#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=4e18;
int c,t,n,d,a[N],las[N],f1[N],g1[N],f2[N],g2[N];
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1,j=1;i<=n;i++){
			while(a[j]+d<a[i]){
				j++;
			}
			las[i]=j;
		}
		las[n+1]=las[n+2]=a[n+1]=a[n+2]=inf;
		for(int i=1;i<=n;i++){
			if(las[i]==i){
				f1[i]=g1[i]=1;
				f2[i]=g2[i]=0;
				continue;
			}
			f1[i]=max(0ll,min(i,las[i+2])-las[i]-1)+1;
			if(a[las[i]]+d<a[i+2]){
				f1[i]+=g1[las[i]];
			}
			g1[i]=max(0ll,min(i,las[i+1])-las[i]-1)+1;
			if(a[las[i]]+d<a[i+1]){
				g1[i]+=g1[las[i]];
			}
			f2[i]=g2[las[i]]+f1[las[i]]-g1[las[i]];
			g2[i]=0;
			if(a[las[i]]+d<a[i+1]){
				g2[i]+=g2[las[i]]; 
			}
			if(a[las[i]+1]+d<a[i+1]){
				g2[i]+=f1[las[i]]-g1[las[i]];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=f2[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}