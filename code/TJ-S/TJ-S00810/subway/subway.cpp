#include<bits/stdc++.h>
using namespace std;
long long w[500005];
typedef pair<long long,long long> PII;
vector<PII>a[500005];
vector<PII>l[505];
long long dd[505][505];
long long fin(){
	long long re=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+ch-'0';
		ch=getchar();
	}
	return re;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dd,0x3f,sizeof dd);
	long long c=fin(),n=fin(),m=fin(),d=fin(),q=fin();
	for(int i=1;i<=m;i++)w[i]=fin();
	for(int i=1;i<=n;i++){
		int k=fin();
		for(int j=1;j<=k;j++){
			long long x=fin(),y=fin();
			a[x].push_back({i,j-1});
			l[i].push_back({x,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int jj=0;jj<l[i].size();jj++){
			int j=l[i][jj].first,wj=l[i][jj].second;
			for(int kk=0;kk<a[j].size();kk++){
				long long k=a[j][kk].first;
				long long wk=l[k][a[j][kk].second].second;
				dd[i][k]=min(dd[i][k],wk+wj); 
				dd[k][i]=min(dd[k][i],dd[i][k]); 
			}
		}
	}
	for(int i=1;i<=n;i++)dd[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k)continue;
				dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
				dd[j][i]=min(dd[j][i],dd[i][j]);
			}
		}
	}
	while(q--){
		int x=fin(),y=fin();
		long long ans=1e18;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				PII ii=a[x][i];
				PII jj=a[y][j];
				ans=min(ans,0ll+w[x]+w[y]+(long long)dd[ii.first][jj.first]+l[ii.first][ii.second].second+l[jj.first][jj.second].second);
			}
		}
		printf("%lld\n",ans);
	}
}

