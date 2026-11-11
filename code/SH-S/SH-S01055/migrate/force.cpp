#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,T;

int n;
ll d;

ll s[2000005];

int md[5005];

int f[5005];
int L[5005],R[5005];
int pre[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>s[i];
		
		ll ans=0;
		
		for(int l=1;l<=n;++l){
			md[l]=0,L[0]=R[0]=l;
			for(int j=l+1,p=l;j<=n;++j){
				while(s[j]-s[p]>d) ++p;
				if(j==p) md[j]=1e9;
				else md[j]=md[p]+1;
				if(md[j]<1e9){
					if(md[j]!=md[j-1]) L[md[j]]=j;
					R[md[j]]=j;
				}
			}
			// consider no path
			memset(pre,0,sizeof(pre));
			f[l]=pre[l]=1;
			for(int j=l+1,p=l;j<=n;++j){
				if(md[j]>=1e9) break;
				while(s[j]-s[p]>d) ++p;
				f[j]=pre[R[md[j]-1]]-pre[max(L[md[j]-1],p)-1];
				if(f[j]==2) ++ans;
				pre[j]=pre[j-1]+min(f[j],3);
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
