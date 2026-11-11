#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e6+15;
int _,T,n,d,a[maxn],nxt[maxn],val[2][maxn],fa[20][maxn];
int C[maxn],V[2][maxn],dep[maxn];
long long ans;
int sve(int x,int y){
	int res=0;
	if(x>1&&a[y]-a[x-1]<=d) ++res;
	if(x>2&&a[y]-a[x-2]<=d) ++res;
	return res;
}
bool chk(int x,int y,int z){
	return a[z]-a[y-1]<=d&&(x>1&&a[y-1]-a[x-1]<=d);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>T;
	while(T--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,p=1;i<n;i++){
			while(p<n&&a[p+1]-a[i]<=d) ++p;
			nxt[i]=p==i?0:p;
		}
		for(int i=1;i<=n;i++){
			int cnt=0,lst=i;
			for(int j=nxt[i];j;j=nxt[j]){
				if(cnt>1) break;
				if(cnt==1) ++ans;
				if(n<=5000){
					for(int x=j+1;x<=nxt[j]-1;x++){
						if((lst!=i&&chk(lst,j,x))||cnt+sve(j,x)!=1) continue;
						++ans;
					}
				}
				else{
					int l=j+1,r=nxt[j]-1,pos=nxt[j];
					while(l<=r){
						int mid=(l+r)>>1;
						if((lst!=i&&chk(lst,j,mid))||cnt+sve(j,mid)!=1) l=mid+1;
						else pos=mid,r=mid-1;
					}
					l=j+1,r=nxt[j]-1;
					int pp=nxt[j];
					while(l<=r){
						int mid=(l+r)>>1;
						if(cnt+sve(j,mid)==0) pp=mid,r=mid-1;
						else l=mid+1;
					}
					if(pp-pos>=0) ans+=pp-pos;
				}
				if(nxt[j]){
					cnt+=sve(j,nxt[j]);
					if(lst!=i&&chk(lst,j,nxt[j])) break;
				}
				lst=j;
			}
		}
		for(int i=1;i<=n;i++){
			nxt[i]=val[0][i]=val[1][i]=dep[i]=C[i]=V[0][i]=V[1][i]=0;
			for(int j=0;j<=19;j++) fa[j][i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
