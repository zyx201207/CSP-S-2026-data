#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2000000
//		   1234567
typedef unsigned long long ull;
typedef long long ll;
int c,t;
int n,d;
int a[N];
struct pr{
	int id,dep;
};
int pt[N];
int is[N];
int bfs(int s){
	memset(is,0,n*4);
	queue<pr> q;
	q.push(pr{s,0});
	while(!q.empty()){
		pr xx=q.front();
		q.pop();
		int i=xx.id;
		int dep=xx.dep+1;
		printf("at%d:",i);
			if(pt[i]==0){
				pt[i]=xx.dep;
				is[i]++;
			}else if(pt[i]==xx.dep){
				is[i]++;
			}
		for(int j=i+1;a[j]-a[i]<=d&&j<n;++j){
			printf("%d,",j);
			q.push(pr{j,dep});
		}
		puts("");
	}
	int cnt=0;
	printf("%d:",s);
	for(int i=s;i<n;++i){
		printf("%d,",is[i]);
		if(is[i]==2){
			cnt++;
		}
	}
	puts("");
	return cnt;
}
int A(){
	ll del=ll(a[1])-a[0];
	int nd=d/del;
	//printf(":%lld/%lld=%lld\n",d,del,nd);
	if(nd==0||nd==1||nd>=n){
		return 0;
	}
	return n-nd-nd+1;
}
int B(){
	return 0;
}
void solve(){
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	if(n<=2){
		printf("0");
		return;
	}
	if(a[n-1]-a[0]<=d){
		printf("%d\n",B());
		return;
	}
	int del=a[1]-a[0];
	bool isa=1;
	for(int i=2;i<n;++i){
		if(a[i]-a[i-1]!=del){
			isa=0;break;
		}
	}
	if(isa){
		printf("%d\n",A());
		return;
	}
	int cnt=0;
	for(int i=0;i<n;++i){
		cnt+=bfs(i);
	}
	printf("%d\n",cnt);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
}