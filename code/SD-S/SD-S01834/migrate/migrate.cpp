#include<bits/stdc++.h>
#define int long long
#define deb(a) cerr<<#a<<"="<<(a)<<endl 
using namespace std;

const int maxn=2e6+10;

int c,T;

int n,D;
int a[maxn]; 

int nx[maxn],pr[maxn];

int f0[maxn],f1[maxn],f2[maxn];

void sol(){
	cin>>n>>D;
	
	for(int i=0;i<=n+1;++i)f0[i]=f1[i]=f2[i]=0;
	
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1,j=1;i<=n;++i){
		while(j+1<=n&&a[j+1]-a[i]<=D)++j;
		nx[i]=j;
	}
	for(int i=1,j=1;i<=n;++i){
		while(a[i]-a[j]>D)++j;
		pr[i]=j;
	}
	for(int i=n;i;--i){
		f0[i]=1;
		for(int j=nx[i]-1;pr[j]==i;--j)++f0[i];
		if(i<nx[i]&&pr[nx[i]]==i)f0[i]+=f0[nx[i]]; 
	}
	for(int i=n;i;--i){
		if(i<nx[i]&&pr[nx[i]]==i)f1[i]+=f1[nx[i]];
		
		{
			int a=nx[i];
			int b=nx[a];
			
			int c=pr[b];
			int d=pr[c];
			
			if(i==d && i<a&&a<b&&i<c&&c<b && c+1==a)
				f1[i]+=f0[b];
		}
		{
			int a=nx[i];
			int b=nx[a];
			//>a,<b;pr=a-1;pr[a-1]=i
			if(i<a&&a<b&&pr[a-1]==i){
				//a+1~b-1, how many s.t. pr==a-1
				for(int j=b-1;j>a&&a-1<=pr[j];--j)
					f1[i]+=(a-1==pr[j]);
			}
		}
	}
	
	
	for(int i=n;i;--i){
		if(i<nx[i])f2[i]+=f1[nx[i]];
		 
		{
			int a=nx[i];
			int b=nx[a];
			
			int c=pr[b];
			
			if(i<a&&a<b&&i<c&&c<b && c+1==a)
				f2[i]+=f0[b];
		}
		{
			int a=nx[i];
			int b=nx[a];
			//>a,<b;pr=a-1;pr[a-1]=i
			if(i<a&&a<b){
				//a+1~b-1, how many s.t. pr==a-1
				for(int j=b-1;j>a&&a-1<=pr[j];--j)
					f2[i]+=(a-1==pr[j]);
			}
		}
	}

	long long ans=0;
	for(int i=1;i<=n;++i)ans+=f2[i];
	cout<<ans<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;while(T--)sol();
}
