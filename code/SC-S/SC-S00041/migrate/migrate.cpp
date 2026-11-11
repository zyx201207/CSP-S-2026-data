#include<bits/stdc++.h>
using namespace std;
long long a[(int)2e6+10];
long long n,d;
long long check(int u,int v){
	int ans=0;
	while(u<v){
		if(a[v]-a[u]<=d)return ans+1;
		if(a[u+1]-a[u]>d)return -1;
		int l=u,r=v;
		while(l<r){
			int mid=(l+r)/2;
			if(a[mid]-a[l]<=d)l=mid+1;
			else r=mid;
		}
		ans++;
		u=l-1;
	}
}
int res=0;
void dfs(int u,int v,int minv,int num){
	if(a[v]-a[u]<=d){
		if(num+1==minv){
			res++;
			return;
		}
	}
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]<=d)dfs(i,v,minv,num+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,c;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			long long x=a[2]-a[1];
			if(d<=x)cout<<0<<'\n';
			else{
				long long ans=n-2*(long long)ceil(((double)d/x))+1;
				ans>0?cout<<ans:cout<<0;
				cout<<'\n';
			}
		}else{
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					res=0;
					long long minv=check(i,j);
					if(minv==-1)continue;
					//cout<<minv<<' ';
					dfs(i,j,minv,0);
					if(res==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}		
	}
	
	
	

	return 0;
}
