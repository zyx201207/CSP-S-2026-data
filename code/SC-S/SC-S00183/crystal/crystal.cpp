#include<bits/stdc++.h>
using namespace std;
int const N=5e5+114;
int const M=25e6+114;
int n;
long long m,a[N];
struct edge{
	int a,b;
	long long l;
};
vector<edge> e;
bool cmp(edge x,edge y){
	return x.l<y.l;
}
int count(int x){
	long long tt=0;
	int cnt=1;
	for(int i=1;i<=e.size();i++){
		if(x==e[i].b){
			tt+=e[i].l;
			if(tt>m) break;
			cnt++;
		}
	}
	return cnt;
}
void test1(){
	printf("n  %d\nm  %lld\n\na[i]\n",n,m);
	for(int i=1;i<=n;i++) printf("a[%d]%3lld\n",i,a[i]);
	cout<<'\n';
}
void test2(){
	printf("e[i]\n");
	for(int i=0;i<e.size();i++){
		int x1=a[e[i].a];
		int x2=a[e[i].b];
		int x3=e[i].l;
		printf("a[%d]%3d  a[%d]%3d%3lld\n",e[i].a,x1,e[i].b,x2,x3);
	}
	cout<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
//	test1();
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			long long l=a[j]-a[i];
			if(l>m) continue;
			e.push_back({i,j,l});
			if(l==0) e.push_back({j,i,0});
		}
	}
	sort(e.begin(),e.end(),cmp);
	
//	test2();
	
	int ans=-1;
	for(int i=1;i<=n;i++) ans=max(ans,count(i));
	cout<<ans;
	return 0;
}
