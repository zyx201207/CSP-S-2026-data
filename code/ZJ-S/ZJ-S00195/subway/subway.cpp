#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500005],l;
int mp[505][505];
vector <int> f[500005];
vector <int> tf[500005];
vector <int> ta[505];
vector <int> t[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	int qwqqwq=pow(2,50);
	//printf("%lld",qwqqwq);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=qwqqwq;
			if(i==j) mp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&l);
		for(int j=1;j<=l;j++){
			int t1,t2;
			scanf("%lld %lld",&t1,&t2);
			ta[i].push_back(t1);
			t[i].push_back(t2);
			for(int k=0;k<f[t1].size();k++){
				mp[i][ f[t1][k] ]=mp[ f[t1][k] ][i]=min(mp[i][ f[t1][k] ],t2+tf[t1][k]);
			}
			f[t1].push_back(i);
			tf[t1].push_back(t2);
		}
	}
	/*
	for(int j=1;j<=m;j++){
		cout<<j<<endl;
		for(int k=0;k<f[j].size();k++){
			cout<<f[j][k]<<" "<<tf[j][k]<<endl;
		}
		cout<<endl<<endl<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",mp[i][j]);
		}
		printf("\n");
	}
	*/
	for(register int k=1;k<=n;k++){
		for(register int i=1;i<=k;i++){
			for(register int j=k;j<=n;j++){
				mp[i][j]=mp[j][i]=min(mp[i][j],mp[i][k]+mp[k][j]);
				//cout<<k<<" "<<i<<" "<<j<<" "<<mp[i][j]<<endl;
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int ans=qwqqwq;
		int sx,ey;
		scanf("%lld %lld",&sx,&ey);
		if(sx==ey){
			printf("0\n");
			continue;
		}
		for(int j=0;j<f[sx].size();j++){
			for(int k=0;k<f[ey].size();k++){
				ans=min(ans,mp[f[sx][j]][f[ey][k]]+tf[sx][j]+tf[ey][k]);
			}
		}
		printf("%lld\n",ans+a[sx]+a[ey]);
	}
	return 0;
}
//floyd
//ma de bie zai gei wo bao 0 le
//wo qu nian jiu shi zhe yang si de
//wo zheng qiu ni le
//da yang li quan guo le
//gei wo 100 ba
//dancing all night pray we're next together it's a breakthrough
//it's a breakthrough
