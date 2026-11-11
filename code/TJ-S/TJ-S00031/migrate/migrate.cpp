#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int C,t,n,a,s,c,v[2000001],b[2000001];
long long d,x[2000001];
struct N{
	int a,s;
};
queue<N> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
		}
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		while(!q.empty()) q.pop();
		q.push({1,1});
		while(!q.empty()){
			a = q.front().a;
			s = q.front().s + 1;
			q.pop();
			for(int i = a + 1;i <= n && x[i] - x[a] <= d;i++){
				if(!v[i]){
					q.push({i,s});
					v[i] = s;
				}else if(v[i] == s) b[i]++;
			}
		}
		c = 0;
		for(int i = 1;i <= n;i++){
			if(b[i] == 1) c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
