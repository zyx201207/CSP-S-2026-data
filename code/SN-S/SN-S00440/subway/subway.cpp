#include<bits/stdc++.h>
using namespace std;
long long xxx,yyy,xx,t[507][507],c,n,m,d,q,a[500007],aa,bb,k,tt[503][200003],ans;
vector<long long>z[500007];
bool tf[507][500007],xl[507];
long long bfs(long long x,long long y,long long zz){
	long long anss=0x3f3f3f3f;
	if(zz==0){
		for(long long i=0;i<z[x].size();i++){
			xl[z[x][i]]=1;
//			cout<<z[x][i];
			anss=min(anss,bfs(x,y,z[x][i])+tt[z[x][i]][x]);
			xl[z[x][i]]=0;
		}
		return anss;
	}
	if(tf[zz][y]) return tt[zz][y];
	for(long long i=1;i<=n;i++){
//		cout<<i<<endl;
		if(xl[i]||t[zz][i]>100000000000){
//			cout<<t[zz][i]<<' '<<1<<endl;
			continue;
		}
		xl[i]=1;
		anss=min(anss,bfs(x,y,i)+t[zz][i]);
		xl[i]=0;
	}
	return anss;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tt,0x3f3f3f3f,sizeof(tt));
	memset(t,0x3f3f3f3f,sizeof(t));
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			scanf("%lld",&aa);
			scanf("%lld",&bb);
			z[aa].push_back(i);
			tt[i][aa]=min(tt[aa][i],bb),tf[i][aa]=1;
		}
	}
	for(long long i=1;i<=m;i++){
		for(int j=0;j<z[i].size();j++){
			xx=z[i][j];
			for(int h=0;h<z[i].size();h++){
				if(xx==z[i][h]) continue;
//				cout<<tt[z[i][j]][i]+tt[z[i][h]][i]<<endl;
				t[z[i][j]][z[i][h]]=tt[z[i][j]][i]+tt[z[i][h]][i];
				t[z[i][h]][z[i][j]]=tt[z[i][j]][i]+tt[z[i][h]][i];
			}
		}
	}
//	cout<<t[1][2]<<endl;
	for(long long i=1;i<=q;i++){
		ans=0x3f3f3f3f;
		cin>>xxx>>yyy;
		ans=a[xxx]+a[yyy]+bfs(xxx,yyy,0);
		cout<<ans<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

