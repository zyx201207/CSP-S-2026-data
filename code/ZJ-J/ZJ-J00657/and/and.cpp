#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
struct node{
	long long v,one;
	bool operator<(const node& py)const{
		if(one!=py.one)return one>py.one;
		return v>py.v;
	}
}a[200005];
int n,m;
long long ans=LONG_LONG_MAX;
void init(int x){
	long long tmp=a[x].v;
	while(tmp){
		a[x].one+=(tmp&1);
		tmp>>=1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].v);
		init(i);
	}sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		ans&=a[i].v;
	}printf("%lld\n",ans);
	return 0;
}
