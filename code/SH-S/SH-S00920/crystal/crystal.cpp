#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
}c[1000005];
long long n,m,cnt,ans,z=1,f;
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>c[i].a;
		c[i].b=abs(c[i].a-c[i-1].a);
		if(c[i].b!=c[i-1].b&&i>1)f=1;
	}
	if(f==0){
		m=m/c[n].b;
		long long p=0;
		for(long long i=1;i<=n;i++){
			m-=i;
			if(m<0)break;
			p++;
		}
		cout<<p+1;
		return 0;
	}
	sort(c+1,c+n+1,cmp);
	ans=1;
	for (long long i=2;i<=n;i++){
		cnt+=(c[i].a-c[i-1].a)*(i-z);
		if(cnt>m){
			while(cnt>m){
				cnt=cnt-c[i].a+c[z].a;
				z++;
			}
		}
		ans=max(ans,i-z+1);
	}
	cout<<ans;
	return 0;
} 
