#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int,int> pii;
const int _MAXn=2e6+100;

int n;
i64 d,num[_MAXn];
int poi[_MAXn];
int lpoi[_MAXn],rpoi[_MAXn];
int lcnt[_MAXn],rcnt[_MAXn];
int flg[_MAXn];
vector<pii> seq;
void Solve(){
	seq.clear();
	for(int i=1;i<=n;i++)lpoi[i]=rpoi[i]=lcnt[i]=rcnt[i]=flg[i]=poi[i]=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	queue<pair<i64,int>> qu;
	for(int i=1;i<=n;i++){
		qu.push({num[i],i});
		while(!qu.empty()&&num[i]-qu.front().first>d){
			int tmp=qu.front().second;
			poi[tmp]=i-1;
			qu.pop();
		}
	}
	while(!qu.empty()){
		int tmp=qu.front().second;
		poi[tmp]=n;
		qu.pop();
	}
//	for(int i=1;i<=n;i++)printf("%d ",poi[i]);printf("\n");
	int tmp=1;
	for(int i=1;;i=poi[i]){
		if(poi[i-1]==i)rpoi[tmp]=i,lpoi[i]=tmp,tmp=i;
		if(i==poi[i])i++;
		if(i>n)break;
	}
	for(int i=1;i<=n;i++){
		if(poi[i]-i>1&&poi[poi[i]-1]<=poi[poi[i]]&&poi[poi[i]-2]!=poi[poi[i]-1]){
			flg[i+1]++,flg[poi[poi[i]-1]]--;
			seq.push_back({i,poi[poi[i]-1]});
		}
	}
	for(int i=1;i<=n;i++)flg[i]+=flg[i-1];
	for(int i=1;i<=n;i++)flg[i]+=flg[i-1];
//	for(int i=1;i<=n;i++)printf("%d ",lpoi[i]);printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",rpoi[i]);printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",flg[i]);printf("\n");
	for(int i=1;;){
		lcnt[rpoi[i]]=lcnt[i]+1;
		if(flg[rpoi[i]]-flg[i])lcnt[rpoi[i]]=0;
		if(rpoi[i]==0)i++;
		else i=rpoi[i];
		if(i>n)break;
	}
	for(int i=n;;){
		rcnt[lpoi[i]]=rcnt[i]+1;
		if(flg[i]-flg[lpoi[i]])rcnt[lpoi[i]]=0;
		if(lpoi[i]==0)i--;
		else i=lpoi[i];
		if(i<=0)break;
	}
//	for(int i=1;i<=n;i++)printf("%d ",lcnt[i]);printf("\n");
//	for(int i=1;i<=n;i++)printf("%d ",rcnt[i]);printf("\n");
	i64 ans=0;
	for(auto it:seq){
		int l=it.first,r=it.second;
//		printf("(%d,%d)",l,r);
		ans+=(lcnt[l]+1)*(rcnt[r]+1);
	}
	printf("%lld\n",ans);
}

int cid,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cid,&T);
	while(T--){
		Solve();
	}
	return 0;
}
