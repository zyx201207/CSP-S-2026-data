#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5,M=505;
int h[M],e[N],ne[N],a[N],ea[N],nea[N],t[N],idx=0,idxa=0;
long long w[N];
long long map[M][M];
int ti[25],tj[25],ti2[25],tj2[25];
void head(int x,int k){
	ne[idx]=h[x];
	e[idx]=k;
	h[x]=idx;
	idx++;
}
void add(int x,int k,int T){
	nea[idx]=a[x];
	ea[idx]=k;
	t[idx]=T;
	a[x]=idx;
	idxa++;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
		a[i]=-1;
	}
	for(int i=0;i<n;i++){
		h[i]=-1;
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int T1,T2;
			scanf("%d%d",&T1,&T2);
			head(i,T1);
			add(T1,i,T2);
		}
		/*
		for(int j=h[i];j!=-1;j=ne[j]){
			cout<<e[j]<<" ";
		}
		cout<<endl;
		*/
	}
	/*
	for(int i=1;i<=m;i++){
		for(int j=a[i];j!=-1;j=nea[j]){
			cout<<ea[j]<<" "<<t[j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				map[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int k=0;
		for(int j=a[i];j!=-1;j=nea[j]){
			tj[k]=ea[j];
			ti[k]=t[j];
			k++;
		}
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				if(map[tj[i]][tj[j]]>ti[i]+ti[j]){
					map[tj[i]][tj[j]]=ti[i]+ti[j];
				}
			}
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		long long x,y,minn=1e18;
		scanf("%lld%lld",&x,&y);
		int k1=0,k2=0;
		for(int j=a[x];j!=-1;j=nea[j]){
			tj[k1]=ea[j];
			ti[k1]=t[j];
			k1++;
		}
		for(int j=a[y];j!=-1;j=nea[j]){
			tj2[k2]=ea[j];
			ti2[k2]=t[j];
			k2++;
		}
		for(int i=0;i<k1;i++){
			for(int j=0;j<k2;j++){
				minn=min(map[tj[i]][tj2[j]]+ti[i]+ti2[j],minn);
			}
		}
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
}
