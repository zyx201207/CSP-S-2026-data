#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;

namespace WDY_Hodur{

int c,T;
int n,d;
int a[N],ans;

int f[N],g[N];
int sn[N],lst[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		for(int s=1;s<=n;s++){
			for(int i=0;i<=n;i++)f[i]=g[i]=sn[i]=lst[i]=0;
			f[s]=1,g[s]=1;
			lst[0]=s-1,lst[1]=s;
			sn[s]=1;
			for(int i=s+1;i<=n;i++){
				int j=max(lower_bound(a+1,a+1+n,a[i]-d)-a,s);
				f[i]=f[j]+1;
				g[i]+=sn[lst[f[j]]]-sn[j-1];
				sn[i]=sn[i-1]+g[i];
				lst[f[i]]=i;
			}
			for(int t=s;t<=n;t++){
				ans+=(g[t]==2);
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}

}

signed main(){
	WDY_Hodur::main();
	return 0;
}
