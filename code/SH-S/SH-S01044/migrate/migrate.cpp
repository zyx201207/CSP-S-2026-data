#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
void optimize(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
int c,t,n,d,x[N],top[N],sum[N],rev[N],ans;
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
//	optimize();
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) top[i]=rev[i]=n+1;
		for(int i=1;i<=n;i++) cin>>x[i];
		x[n+1]=2e18;
		int j=1;
		for(int i=1;i<=n;i++) {
			while(x[j]-x[i]<=d) j++;
			if(x[j]-x[i]>d) j--;
			top[i]=j;
			if(rev[j]==n+1) rev[j]=i;
		}
		//for(int i=1;i<=n;i++)cout<<"?"<<i<<" "<<rev[i]<<"\n";
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i+1;j--){
				if(rev[j]==n+1) continue;
				int p=i,p2=0;
				if(rev[j]<p) p2=j;
				else p2=rev[j];
				while(p-p2<0 && p!=n+1)
					p=top[p];
				if(p==1+n) continue;
				if(p-rev[j]==1) ans++;//cout<<i<<" "<<p<<" "<<rev[j]<<" "<<j<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
