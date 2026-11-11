#include<bits/stdc++.h>
using namespace std;
long long a[510000];
map<long long,long long>x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long f=0;
	for(long long i=1;i<=n;i++){
		long long d;
		cin>>d;
		if(x[d]==0){
			a[++f]=d;
		}
		x[d]++;
	}
	sort(a+1,a+1+f);
	long long ans1=x[a[1]];
	for(long long i=2;i<=f;i++){
		long long ans=0,g=m;
		ans+=x[a[i]];
		for(long long j=i-1;j>0;j--){
			long long l=0;
			long long r=a[i]-a[j];
			long long h=g/r;
			if(x[a[j]]<h)h=x[a[j]];
			else l=1;
			ans+=h;
			g-=h*r;
			if(l==1)break;
		}
		ans1=max(ans1,ans);
	}
	cout<<ans1;
	return 0;
}
