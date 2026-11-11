#include<bits/stdc++.h>
using namespace std;
struct sch{
	long long a;
	string s;	
}a[200010];
long long sum;
long long n,m;
bool f[200010];
bool cmp(sch a,sch b){
	return a.a<b.a;
}
bool cmp1(sch a,sch b){
	return a.s>b.s;
}
void dfs(long long ans,long long id){
	if(id==m){
		sum=max(sum,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[a[i].a]==0){
			f[a[i].a]=1;
			dfs(ans&a[i].a,id+1);
			f[a[i].a]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		long long o=a[i].a;
		while(o!=0){
			a[i].s+=char(o%2);
			o/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[n].a;
		return 0;
	}
	sort(a+1,a+n+1,cmp1);
	sum=a[1].a;
	for(int i=1;i<=m;i++){
		sum&=a[i].a;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		f[a[i].a]=1;
		dfs(a[i].a,1);
	}
	cout<<sum<<endl;
	return 0;
}
