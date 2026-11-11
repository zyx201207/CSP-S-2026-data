#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define LL long long
using namespace std;
const int inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;
const int tianyiblue=0x66ccff;
int cid,t,n,d,a[2000005],stp[2000005],f[2000005],s[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<n;++i){
			int lim=n,cnt=0;stp[i]=0,f[i]=1,s[i]=1,f[i-1]=0,s[i-1]=0;
			for(int j=i;j<n;){
				int k=j;
				while(k<n&&a[k+1]-a[j]<=d)++k;
				if(k==j){
					lim=k;
					break;
				}++cnt;
				while(j<k)++j,stp[j]=cnt;
			}
			for(int j=i+1,k=i,lst=i;j<=lim;++j){
				if(stp[j]!=stp[j-1])lst=j-1;
				while(a[j]-a[k]>d)++k;
				f[j]=s[lst]-s[k-1],s[j]=s[j-1]+f[j];
			}
			for(int j=i;j<=lim;++j)ans+=(f[j]==2);
		}cout<<ans<<'\n';
	}
	return 0;
}
