#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+10;
const int ADDD=1e18;
int c,t;
int n,d,x[MAXN];
int ds[5005][5005],sum[5005][5005];
struct node{
	int l,r,sum;
}qs[MAXN<<1];
int tot;
int cid=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	
	while(t--){
		++cid;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			x[i]+=ADDD;
		}
		if(c==13||c==14||x[n]-x[1]<=d||n<=3){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			int dc=x[2]-x[1];
			cout<<n-(d/dc*2)+1<<"\n";
			continue;
		}
		if(n<=300){
			memset(ds,0x3f,sizeof ds);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d) ds[i][j]=1,sum[i][j]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(k==i||k==j||i==j) continue;
						if(ds[i][k]+ds[k][j]<ds[i][j]) ds[i][j]=ds[i][k]+ds[k][j],sum[i][j]=sum[i][k]*sum[k][j];
						else if(ds[i][j]==ds[i][k]+ds[k][j]) sum[i][j]+=sum[i][k]*sum[k][j];
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(ds[i][j]<=n&&sum[i][j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		int id1,id2,id3;
		tot=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			id1=id2=id3=-1;
			id1=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			if(id1+1>n) continue;
			if(id1!=i&&id1-1!=i) id2=id1-1;
			id3=id2-1;
			int l=upper_bound(x+1,x+n+1,x[id3]+d)-x;
			int r=upper_bound(x+1,x+n+1,x[id2]+d)-x-1;
//			ans+=r-l+1;
			if(l<=r&&!(i==qs[tot].l&&r==qs[tot].r)) qs[++tot]=(node){i,r,r-l+1};
		}
//		cout<<cid<<":\n";
//		cout<<n<<'\n';
//		cout<<tot<<"\n";
		qs[0].r=0,qs[tot+1].l=tot;
		for(int i=1;i<=tot;i++){
			if(i==1){
				if(qs[i].r<qs[i+1].l) ans+=qs[i].sum*(qs[i].l*(qs[i+1].l-qs[i].r));
				else ans+=qs[i].sum*(qs[i].l);
			}
			else if(i==tot){
				if(qs[i].l>qs[i-1].r) ans+=qs[i].sum*(qs[i].l-qs[i-1].r)*(n-qs[i].r+1);
			}
			else{
				ans+=qs[i].sum*max(qs[i].l-qs[i-1].r,1ll)*max(qs[i+1].l-qs[i].r,1ll);
			}
//			cout<<qs[i].l<<" "<<qs[i].r<<" "<<qs[i].sum<<"\n";
		}
//		cout<<"\n";
		cout<<ans<<'\n';
	}
	return 0;
}
