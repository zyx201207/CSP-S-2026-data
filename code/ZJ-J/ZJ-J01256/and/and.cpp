#include<bits/stdc++.h>
#define IO freopen("and.in","r",stdin);freopen("and.out","w",stdout);
using namespace std;
typedef long long ll;
int n,m;
int A[200010];
int cnt[31];
ll ans=0;
signed main(){
	IO;
	scanf("%d%d",&n,&m);
	int ma=0;
	multiset<int>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		s.insert(A[i]);
	}
	for(int i=31;i>=0;i--){//
		multiset<int>ts;
//		for(set<int>::iterator it=s.begin();it!=s.end();it++){
//			printf("%d ",*it);
//		}puts("");
		for(multiset<int>::iterator it=s.begin();it!=s.end();it++){
			if(((*it)>>i)&1)
				ts.insert(*it);
		}
//		if(i==0){
//			printf("%d\n",ts.size());
//		for(set<int>::iterator it=s.begin();it!=s.end();it++){
//			printf("%d ",*it);
//		}puts("");
//		}
		if(ts.size()>=m){
			s=ts;
			ans+=(1<<i);
		}
	}
	printf("%d",ans);
	return 0;
}