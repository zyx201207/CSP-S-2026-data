#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200050],p[200050],s[200050];
int p2[200050];
char c[200050],c2[200050];
//map<int,int>lsh;
vector<int>v;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	v.push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		p[i]=p[i-1]+a[i];
		v.push_back(p[i]);
	}
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+a[i];
		v.push_back(s[i]);
		p2[n-i+1]=s[i];
		c2[i]=c[n-i+1];
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<(int)v.size()-1;i++){
		int id1=upper_bound(p,p+n+1,v[i])-p;
		int id2=upper_bound(p2,p2+n+1,v[i])-p2;
		//printf("! %lld %lld %lld\n",i,id1,id2);
		if(c[id1]==c2[id2])continue;
		ans+=v[i+1]-v[i];
	}
	printf("%lld\n",ans/2);
	/*for(int i:v)printf("%lld ",i);
	putchar('\n');
	for(int i=1;i<=n;i++)printf("%lld ",p[i]);
	putchar('\n');
	for(int i=1;i<=n;i++)printf("%lld ",p2[i]);*/
}
