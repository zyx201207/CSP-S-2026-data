#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c;long long x=0,f=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')f=-f;
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
	return x*f;
}
long long sd[505][505];//1-index
int c,n,m,d,q,tmp,tmp1,tmp2;
long long w[500005];//1-index
struct node{
	int a;//1-index subwaystation
	long long t;
};
struct pairs{
	int lineid,which;//1-index,0-index
};
vector<node> line[505];//1-index subwayline 1-index subwaystation
vector<pairs> cnt[500005];//0-index subwaystation
bool cmp1(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j){
			sd[i][j]=-1;
			if(i==j)sd[i][j]=0;
		}
	for(int i=1;i<=n;++i){
		tmp=read();
		for(int j=0;j<tmp;++j){
			tmp1=read();tmp2=read();
			line[i].push_back({tmp1,tmp2});
			cnt[tmp1-1].push_back({i,j});
		}
	//	sort(line[i].begin(),line[i].end(),cmp1);
	}
	for(int i=0;i<m;++i){
		if(cnt[i].size()>=2){
			for(int j=0;j<cnt[i].size();++j){
				for(int k=j+1;k<cnt[i].size();++k){
					long long tj=line[cnt[i][j].lineid][cnt[i][j].which].t,tk=line[cnt[i][k].lineid][cnt[i][k].which].t;
					if(sd[cnt[i][j].lineid][cnt[i][k].lineid]==-1||tj+tk<=sd[cnt[i][j].lineid][cnt[i][k].lineid]){
						sd[cnt[i][k].lineid][cnt[i][j].lineid]=sd[cnt[i][j].lineid][cnt[i][k].lineid]=tj+tk;

					}
				}
			}
		}
	}
/*	n=4;
	sd[0][1]=2;	sd[0][2]=5;	sd[0][3]=-1;
	sd[1][0]=2;	sd[1][2]=-1;	sd[1][3]=8;
	sd[2][0]=5;	sd[2][1]=-1;	sd[2][3]=4;
	sd[3][0]=-1;	sd[3][1]=8;	sd[3][2]=4;*/
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%lld ",sd[i][j]);
		}
		puts("");
	}*/
	//puts("sd");
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(sd[i][k]!=-1&&sd[k][j]!=-1){
					if(sd[i][k]+sd[k][j]<sd[i][j]||sd[i][j]==-1){
						sd[j][i]=sd[i][j]=sd[i][k]+sd[k][j];
					}
				}
			}
		}
	}
	while(q--){
		tmp1=read();tmp2=read();
		long long ans=w[tmp1]+w[tmp2];
		--tmp1;--tmp2;
		long long minn=LONG_LONG_MAX;
		for(int i=0;i<cnt[tmp1].size();++i){
			for(int j=0;j<cnt[tmp2].size();++j){
				minn=min(minn,line[cnt[tmp1][i].lineid][cnt[tmp1][i].which].t+line[cnt[tmp2][j].lineid][cnt[tmp2][j].which].t+sd[cnt[tmp1][i].lineid][cnt[tmp2][j].lineid]);
			//	printf("tmp1=%d,tmp2=%d,line[cnt[tmp2][i].lineid][cnt[tmp2][i].which].t:(%d,%d)=%lld\n",tmp1,tmp2,cnt[tmp2][i].lineid,cnt[tmp2][i].which,line[cnt[tmp2][j].lineid][cnt[tmp2][j].which].t);
			//	printf("minn=%lld+%lld+%lld\n",line[cnt[tmp1][i].lineid][cnt[tmp1][i].which].t,line[cnt[tmp2][j].lineid][cnt[tmp2][j].which].t,sd[cnt[tmp1][i].lineid][cnt[tmp2][j].lineid]);
			}
		}
	//	printf("%lld+%lld\n",ans,minn);
		printf("%lld\n",ans+minn);
	}
	return 0;
}
