#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],ans[32],expp[32];
struct binary{
	bool t[32];
	long long id;
}x[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	expp[0]=1;
	for(int i=1;i<32;i++)expp[i]=expp[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,[](long long p,long long q){return p>q;});
	for(int i=1;i<=n;i++){
		long long y=a[i],cnt=0;
		while(y){
			x[i].t[cnt]=y%2;
			cnt++;
			y/=2;
		}
		x[i].id=i;
	}
	long long bound=n;
	for(int j=31;j>=0;j--){
		sort(x+1,x+bound+1,[j](binary p,binary q){
			if(p.t[j]==q.t[j])return p.id<q.id;
			return p.t[j]>q.t[j];
		});
		int cnt=0;
		for(int i=1;i<=bound;i++)cnt+=x[i].t[j];
		if(cnt>=m){
			ans[j]=1;
			bound=cnt;
		}
	}
	long long anss=0;
	for(int i=0;i<32;i++)anss+=ans[i]*expp[i];
	cout<<anss;
	return 0;
}
