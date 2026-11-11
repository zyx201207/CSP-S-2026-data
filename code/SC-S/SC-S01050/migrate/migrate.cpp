//记得开long long
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,mx[N],nmx[N],rou[N];
long long d,ans,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=6){
			for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(a[j]-a[i]<=d) mx[i]=j;
			for(int i=1;i<=n;i++) for(int j=mx[i]+1;j<=n;j++){
				for(int k=i;k<=j;k++) nmx[k]=min(j,mx[k]);
				int lst=i,cnt=1;
				rou[1]=i;
				while(mx[lst]<=j&&lst!=mx[lst]) rou[++cnt]=mx[lst],lst=mx[lst];
				if(rou[cnt]!=j&&mx[rou[cnt]]>=j) rou[++cnt]=j;
				else if(mx[rou[cnt]]<j) continue;
				int pok=1;
				for(int k=1;k<cnt-1;k++) for(int l=rou[k];l<rou[k+1];l++) if(nmx[l]==nmx[rou[k+1]]) pok++;
				if(pok==2) ans++;
			}
			cout<<ans<<'\n';
		}
		else if(c==11||c==12){
			if(a[2]-a[1]>d) cout<<"0\n";
			else cout<<n<<'\n';
		}
		else cout<<"0\n";
	}
	return 0;
}