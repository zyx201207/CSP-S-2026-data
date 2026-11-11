#include<bits/stdc++.h>
using namespace std;
struct N{
	long long z;
	char c;
};
long long n;
N a[200010],b[200010];
vector<N>x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i].z);
		cin>>a[i].c;
		b[n-i+1].z=a[i].z;
		b[n-i+1].c=a[i].c;
	}
	long long l=1,r=1;
	while(l<=n&&r<=n){
		long long mi=min(a[l].z,b[r].z);
		x.push_back({mi,a[l].c});
		y.push_back({mi,b[r].c});
		a[l].z-=mi;
		b[r].z-=mi;
		if(a[l].z==0){
			l++;
		}
		if(b[r].z==0){
			r++;
		}
	}
	long long m1=x.size(),m2=y.size();
	if(m1!=m2){
		printf("-1\n");
		return 0;
	}
	long long ans=0;
	for(long long i=0;i<m1;i++){
		if(x[i].c!=y[i].c){
			ans+=x[i].z;
		}
	}
	ans/=2;
	printf("%lld",ans);
	return 0;
}
