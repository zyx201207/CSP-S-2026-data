#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=2000009;
constexpr ll F=3123456789012345678;
int c,t,n,f[N][2],s[N],ldp[N],rdp[N];
ll d,ans,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=-F,a[n+1]=F,a[n+2]=2*F;
		int L=0,Dl=0,Dr=1,R=1;
		for(int i=1;i<=n;i++){
			while(a[Dr]-a[i]<d) Dr++;
			while(a[R]-a[i]<=d) R++;
			f[i][0]=Dr,f[i][1]=R;
		}
		for(int i=n;i>=1;i--){
			int div=f[i][0],r=f[i][1];
			rdp[i]=s[div]-s[r]+1;
			s[i]=s[i+1]+rdp[i];
		}
		for(int i=1;i<=n;i++){
			while(a[i]-a[L]>d) L++;
			while(a[i]-a[Dl]>=d) Dl++;
			f[i][0]=L,f[i][1]=Dl;
		}
		for(int i=1;i<=n;i++){
			int l=f[i][0],div=f[i][1];
			ldp[i]=s[div-1]-s[l-1]+1;
			s[i]=s[i-1]+ldp[i];
		}
		s[n+1]=s[n+2]=s[n];
		int l=0,v=0;
		for(int r=1;r<=n;r++){
			int x=f[r][0]+1;
			if(x>r) continue;
			while(a[x]-a[l]>d) l++;
			while(a[x+1]-a[v]>d) v++;
			ans+=((ll)(s[v-1]-s[l-1])*(ll)rdp[r]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
