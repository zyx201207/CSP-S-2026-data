#include<bits/stdc++.h>
#define N 2000005
#define ll long long
#define ls(v) ((v)<<1)
#define rs(v) (((v)<<1)|1)
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
//int s[N][N];
int nx[N],pr[N],n;
ll d;
ll a[N];
ll s1[N],s2[N],s3[N],p[N],ans;
vector<int>v[N];
void work(bool ok){
	for(int i=1;i<=n;i++)s2[i]=1,v[i].clear(),p[i]=0;
	for(int i=n,j=n;i>=1;i--){
		while(j>=i&&a[j]-a[i]>d)j--;
		nx[i]=j;//s1[j]++;
	}for(int i=1,j=1;i<=n;i++){
		while(j<=i&&a[i]-a[j]>d)j++;
		pr[i]=j;//s2[j]++;
		if(i!=j)v[j].push_back(i),s2[j]++;
	}//for(int i=1;i<=n;i++)if(i!=pr[i])s1[i]+=s1[pr[i]];
	for(int i=n;i;i--)if(i!=nx[i]&&pr[nx[i]]==i){
		s2[i]+=s2[nx[i]]-1;
	}for(int i=1;i<=n;i++){
		s2[i]--;//cout<<s2[i]<<endl;
	}for(int i=1;i<=n;i++)for(auto vv:v[i])s3[i]+=s2[vv];
	for(int i=n;i>=1;i--)if(i!=nx[i]){
		p[i]=0;int x=i;
		bool ok=0;
		for(auto vv:v[i])if(vv!=nx[x]&&vv==nx[x]-1){//cout<<x<<" "<<vv<<endl;
			p[i]+=v[vv].size();ok=1;
			if(nx[nx[x]]!=nx[x]&&pr[nx[nx[x]]]==vv){
				if(ok)p[x]+=s2[nx[nx[x]]];
				else p[x]--;
			}
		}if(!ok){
			int vv=nx[x]-1;
			if(vv>x){
				ans+=v[vv].size();ok=1;
				if(nx[nx[x]]!=nx[x]&&pr[nx[nx[x]]]==vv){
					if(ok)ans+=s2[nx[nx[x]]];
					else p[x]--;
				}
			}
		}
		if(i!=nx[i]&&pr[nx[i]]==i){
			p[i]+=p[nx[i]];
		}ans+=p[i];
		if(i!=nx[i]&&pr[nx[i]]!=i&&pr[nx[i]]<i)ans+=p[nx[i]];
		//cout<<p[i]<<endl;
	}//cout<<s2[4]<<endl;
}
void solve(){
	scanf("%d%lld",&n,&d);//cout<<n;
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s1[i]=1;s2[i]=1;s3[i]=0;
	}work(1);
	for(int i=1;i<=n;i++)a[i]=-a[i];
	reverse(a+1,a+n+1);
	//work(0);
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}