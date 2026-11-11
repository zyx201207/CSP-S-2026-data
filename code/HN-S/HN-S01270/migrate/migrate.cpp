#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,sum;
};
long long c,T,n,m,dd,q;
long long a[5510];
long long d[5510][5510];
long long sum[5510][5510];
bool kk[5510];
vector<node> e[500550];
void Litter_road1(long long start,long long now){
	for(long long i=0;i<(int)e[now].size();i++){
		long long to=e[now][i].to;
		if(kk[to]==1) continue;
		long long summ=e[now][i].sum;
		if(d[start][to]>d[start][now]+summ)
			d[start][to]=d[start][now]+summ;
		kk[to]=1;
		Litter_road1(start,to);
		kk[to]=0;
	}
}
void Litter_road2(long long start,long long now,long long dep){
	for(long long i=0;i<(int)e[now].size();i++){
		long long to=e[now][i].to;
		if(kk[to]==1) continue;
		long long summ=e[now][i].sum;
//		cout<<start<<" "<<now<<" "<<to<<" "<<d[start][now]+summ<<" "<<d[start][to]<<endl;
		if(d[start][to]==dep+summ)
			sum[start][to]++;
		kk[to]=1;
		Litter_road2(start,to,dep+summ);
		kk[to]=0;
	}
}
void work(){
	int ans=0;
	cin>>n>>dd;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[j]-a[i]<=dd)
				e[i].push_back({j,1});
			else
				break;
		}
	}
	memset(d,63,sizeof(d));
	memset(kk,0,sizeof(kk));
	memset(sum,0,sizeof(sum));
	for(long long i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=n;i++){
		Litter_road1(i,i);
		Litter_road2(i,i,0);
	}
	for(long long i=1;i<=n;i++)
		for(long long j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<d[i][j]<<" "<<sum[i][j]<<endl;
			if(sum[i][j]==2) ans++;
		}
	cout<<ans<<endl;
	for(long long i=1;i<=n;i++)
		e[i].clear();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		work();
	}
}
