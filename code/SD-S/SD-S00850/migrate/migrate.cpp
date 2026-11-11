#include<bits/stdc++.h>
using namespace std;
const int N=2000011;
int C,T,n,l[N],r[N],f1[N],f2[N];
long long d,x[N];
map<array<int,3>,long long>c;
bool t[N];
//int lowbit(int x){
//	return x&(-x);
//}
//void modify(int x,int val){
//	for(int i=x;i<=n;i+=lowbit(i))
//		c[i]+=val;
//}
//long long query(int x){
//	long long res=0;
//	for(int i=x;i>=1;i-=lowbit(i))
//		res+=c[i];
//	return res;
//}
//void bfs(int s){
//	deque<int>q;
//	while(!q.empty()){
//		int x=q.front();
//		q.pop();
//		for(auto y:edges[x])
//			if(y.second==0){
//				if(dis[y.first]>dis[x]){
//					dis[y.first]=dis[x];
//					q.push_front(y.first);
//				}
//			}
//			else{
//				if(dis[y.first]>dis[x]+1){
//					dis[y.first]=dis[x]+1;
//					q.push_back(y.first);
//				}
//				else if(dis[y.first]==dis[x]+1){
//					ans[y]
//				}
//			}
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		l[0]=r[0]=l[n+1]=r[n+1]=0;
//		x[0]=-1ll<<59;x[n+1]=1ll<<59;
		for(int i=1;i<=n;i++){
			int L=i,R=n+1;
			while(L+1<R){
				int M=(L+R)>>1;
				if(x[M]-x[i]<=d)L=M;
				else R=M;
			}
//			if(x[L]-x[i]<=d)L=n+1;
			r[i]=L;
			L=0,R=i;
			while(L+1<R){
				int M=(L+R)>>1;
				if(x[i]-x[M]<=d)R=M;
				else L=M;
			}
//			if(x[R]-x[i]<=d&&R==1)R=0;
			l[i]=R;
		}
//		for(int i=1;i<=n;i++)printf("%d***%d %d\n",i,l[i],r[i]);
//		for(int i=1;i<=n;i++)
//			if(l[r[i]]==i){
//				edges[i].push_back(r[i]);
//				edges[r[i]].push_back(i);
//			}
		for(int i=1;i<=n;i++)t[i]=f1[i]=f2[i]=0;
		for(int i=1;i<=n;i++)
			if(!t[i]){
				t[i]=1;
				f1[i]=1;
				for(int j=i;;j=r[j]){
					if(l[r[j]]!=j||r[j]==j)break;
					t[r[j]]=1;
					f1[r[j]]=f1[j]+1;
				}
			}
		c.clear();
		for(int i=1;i<=n;i++)t[i]=0;
		for(int i=n;i>=1;i--)
			if(!t[i]){
				f2[i]=1;
				t[i]=1;
				for(int j=i;;j=l[j]){
					if(r[l[j]]!=j||l[j]==j)break;
					t[l[j]]=1;
					f2[l[j]]=f2[j]+1;
				}
			}
//		for(int i=1;i<=n;i++)modify(l[i],f2[i]);
		long long ans=0;
//		for(int i=1;i<=n;i++){
//			bfs(i); 
//		}
		for(int i=n;i>=1;i--){
//			for(int j=r[i];j<=r[r[i]];j++)
//				if(l[l[j]]>=i&&r[i]-l[j]==1)
//					ans+=f1[i]*f2[j];
			ans+=1ll*f1[i]*c[{r[i]-1,r[r[i]],i}];
			c[{l[i],i,l[l[i]]}]+=f2[i];
			if(r[i]==i+1&&l[i+1]==i&&l[l[i+1]]==i&&r[r[i]]==i+1)ans-=1ll*f1[i]*f2[i+1];
//			c[l[i]]+=f2[i];
		}
//		for(int i=1;i<=n;i++)ans+=query(r[i]-1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
0 1
7 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 444444444444444417
0 1
6 4
-3 0 1 2 3 4
*/
