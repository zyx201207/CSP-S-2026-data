#include<bits/stdc++.h>
using namespace std;
long long d[3009][3009];
long long x[30009];
vector <long long> es_sp[300009];
long long d_sp[30009];
long long es1_sp_20[500009];
long long es2_sp_20[500009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long nn = 0;
	long long n = 0;
	long long m = 0;
	long long l = 0;//why??
	long long k = 0;
	cin>>nn>>n>>m>>l>>k;
	for(long long f = 1;f<=m;f++){
		scanf("%lld",&x[f]);
//		cin>>x[f];
	}
	if(nn>=12&&nn<=15){
		long long j = 0;
		for(long long f1 = 1;f1<=n;f1++){
			long long o1 = 0;
			scanf("%lld",&o1);
//			cin>>o1;
			for(long long f2 = 1;f2<=o1;f2++){
				long long o2 = 0;
				long long o3 = 0;
				scanf("%lld",&o2);
				scanf("%lld",&o3);
				j=o3;
				es_sp[o2].push_back(m+f1);
				es_sp[m+f1].push_back(o2);
//				cin>>o2>>o3;
			}
		}
		for(long long f1 = 1;f1<=k;f1++){
			for(long long f2 = 1;f2<=n+m;f2++){
				d_sp[f2]=11451419198100000;
			}
			long long o1 = 0;
			long long o2 = 0;
//			cin>>o1>>o2;
			scanf("%lld",&o1);
			scanf("%lld",&o2);
			queue <long long> q;
			q.push(o1);
			d_sp[o1]=0;
			while(!q.empty()){
				long long o = q.front();
				q.pop();
				for(long long f2 = 0;f2<es_sp[o].size();f2++){
					if(d_sp[es_sp[o][f2]]>d_sp[o]+1){
						d_sp[es_sp[o][f2]]=d_sp[o]+1;
						q.push(es_sp[o][f2]);
					}
				}
			}
			printf("%lld\n",d_sp[o2]+x[o1]+x[o2]);
		}
		return 0;
	}
	if(nn>=9&&nn<=11){
		for(long long f1 = 1;f1<=m;f1++){
			for(long long f2 = 1;f2<=m;f2++){
				d[f1][f2]=11451419198100000;
			}
		}
		for(long long f1 = 1;f1<=n;f1++){
			long long o = 0;
			long long o1 = 0;
			long long o2 = 0;
			long long o3 = 0;
			long long o4 = 0;
			cin>>o>>o1>>o2>>o3>>o4;
			d[o1][o3]=o2+o4;
			d[o3][o1]=o2+o4;
		}
		for(long long f1 = 1;f1<=m;f1++){
			for(long long f2 = 1;f2<=m;f2++){
				for(long long f3 = 1;f3<=m;f3++){
					d[f2][f3]=min(d[f2][f3],d[f2][f1]+d[f1][f3]);
				}
			}
		}
		for(long long f = 1;f<=k;f++){
			long long o1 = 0;
			long long o2 = 0;
//			cin>>o1>>o2;
			scanf("%lld",&o1);
			scanf("%lld",&o2);
			printf("%lld\n",d[o1][o2]+x[o1]+x[o2]);
//			cout<<d[o1][o2]+x[o1]+x[o2]<<endl;
		}
		return 0;
	}
	if(nn==20||nn==21){
		long long i = 0;
		long long j = 0;
		long long h = 11451419198100000;
		for(long long f = 1;f<=m;f++){
			es1_sp_20[f]=es2_sp_20[f]=11451419198100000;
		}
		scanf("%lld",&i);
		for(long long f = 1;f<=i;f++){
			long long o1 = 0;
			long long o2 = 0;
			scanf("%lld",&o1);
			scanf("%lld",&o2);
			es1_sp_20[o1]=o2;
		}
		scanf("%lld",&j);
		for(long long f = 1;f<=j;f++){
			long long o1 = 0;
			long long o2 = 0;
			scanf("%lld",&o1);
			scanf("%lld",&o2);
			es2_sp_20[o1]=o2;
			h=min(h,es2_sp_20[o1]+es1_sp_20[o1]);
		}
		for(long long f = 1;f<=k;f++){
			long long o1 = 0;
			long long o2 = 0;
			scanf("%lld",&o1);
			scanf("%lld",&o2);
//			cin>>o1>>o2;
			printf("%lld\n",min(min(es1_sp_20[o1]+es1_sp_20[o2],es2_sp_20[o1]+es2_sp_20[o2]),min(es1_sp_20[o1]+es2_sp_20[o2]+h,es2_sp_20[o1]+es1_sp_20[o2]+h))+x[o1]+x[o2]);
		}
		return 0;
	}
	for(long long f1 = 1;f1<=n+m;f1++){
		for(long long f2 = 1;f2<=n+m;f2++){
			d[f1][f2]=11451419198100000;
		}
	}
	for(long long f1 = 1;f1<=n;f1++){
		long long o1 = 0;
		scanf("%lld",&o1);
//		cin>>o1;
		for(long long f2 = 1;f2<=o1;f2++){
			long long o2 = 0;
			long long o3 = 0;
			scanf("%lld",&o2);
			scanf("%lld",&o3);
//			cin>>o2>>o3;
			d[o2][m+f1]=o3;
			d[m+f1][o2]=o3;
		}
	}
	for(long long f1 = 1;f1<=n+m;f1++){
		for(long long f2 = 1;f2<=n+m;f2++){
			for(long long f3 = 1;f3<=n+m;f3++){
				d[f2][f3]=min(d[f2][f3],d[f2][f1]+d[f1][f3]);
			}
		}
	}
	for(long long f = 1;f<=k;f++){
		long long o1 = 0;
		long long o2 = 0;
//		cin>>o1>>o2;
		scanf("%lld",&o1);
		scanf("%lld",&o2);
		printf("%lld\n",d[o1][o2]+x[o1]+x[o2]);
//		cout<<d[o1][o2]+x[o1]+x[o2]<<endl;
	}
	return 0;
}
