#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500010,M=510,Q=100010;
int c,n,m,d,q,w[N],k[M],x,y;
vector<int>a[M],t[M];
vector<int>b[N],bi[N];
vector<pair<int,int> >common[M][M];
ll calc2(int x,int y){
	ll ans=1e18;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			int idx=-1,idy=-1;
			for(int k=0;k<a[i].size();++k){
				if(a[i][k]==x)
					idx=k;
				}
			for(int k=0;k<a[j].size();++k)
				if(a[j][k]==y)
					idy=k;
			if(~idx&&~idy)
			for(auto v:common[i][j])
				ans=min(ans,
		0ll+w[x]+t[i][idx]+t[i][v.first]+t[j][v.second]+t[j][idy]+w[y]);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%d",w+i);
	for(int i=1;i<=n;++i){
		scanf("%d",k+i);
		for(int j=0;j<k[i];++j){
			int aa,tt;
			scanf("%d%d",&aa,&tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
			b[aa].push_back(i);
			bi[aa].push_back(j);
		}
	}
	for(int i=1;i<=n;++i){
		vector<int>&B=b[i];
		int len=B.size();
		for(int j=0;j<len;++j)
			for(int k=j+1;k<len;++k){
				common[B[j]][B[k]].push_back({bi[i][j],bi[i][k]}),
				common[B[k]][B[j]].push_back({bi[i][k],bi[i][j]});	
			}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		if(n<=3){
			for(int j=1;j<=n;++j){
				int idx=-1,idy=-1;
				for(int k=0;k<a[j].size();++k){
					if(a[j][k]==x)
						idx=k;
					else if(a[j][k]==y)
						idy=k;
				}
				if(~idx&&~idy){
					ans=min(ans,0ll+w[x]+t[j][idx]+t[j][idy]+w[y]);
				}
			}
			if(n>1)
				ans=min(ans,calc2(x,y));
			if(n==3){
				for(int i=1;i<=n;++i)
					for(int j=1;j<=n;++j)
						for(int k=1;k<=n;++k){
							if(i==j||i==k||j==k)continue;
							int idx=-1,idy=-1;
							for(int l=0;l<a[i].size();++l)
								if(a[i][l]==x)
									idx=l;
							
							for(int l=0;l<a[k].size();++l)
								if(a[k][l]==y)
									idy=l;
							
							if(~idx&&~idy)
								for(auto v:common[i][j])
									for(auto v2:common[j][k]){
										ans=min(ans,0ll+
										w[x]+t[i][idx]
										+t[i][v.first]+t[j][v.second]
										+t[j][v2.first]+t[k][v2.second]
										+t[k][idy]+w[y]);
									}
						}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
