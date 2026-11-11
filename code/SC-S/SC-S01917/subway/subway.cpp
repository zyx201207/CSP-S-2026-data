#include<bits/stdc++.h>
using namespace std;

int c,t,n,f[200010],cnt[200010],ans=0,s;
long long x[200010],d;
vector<int>p[200010];
bool v[200010];

long long calc(long long x){
	if(x<0)
		return -x;
	return x;
}

void dfs(int h,int c){
	if(h<s||f[h]==1)
		return;
	if(f[h]!=-1&&c>f[h]){
		return;
	}
	v[h]=1;
	if(f[h]==-1||(c<f[h])){
		cnt[h]=1;
		f[h]=c;
	}else{
		if(cnt[h]<=5){
			cnt[h]++;
		}
	}
	for(auto i:p[h]){
		if(!v[i]||(f[i]==-1||c<=f[i])){
			dfs(i,c+1);
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);	
	while(t--){
		
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(calc(x[i]-x[j])<=d){
					p[i].push_back(j);
					p[j].push_back(i);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			memset(f,-1,sizeof(f));
			memset(v,0,sizeof(v));
			memset(cnt,0,sizeof(cnt));
			s=i;
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(i!=j&&cnt[j]==2){
					ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(calc(x[i]-x[j])<=d){
					p[i].pop_back();
					p[j].pop_back();
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}