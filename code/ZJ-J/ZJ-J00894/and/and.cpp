#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,ma,f[200010],ds,b[200010],s;
struct no{
	long long x,y;
}a[200010];
bool cmp2(no q,no h){return q.x>h.x;}
void dfs(int t,int s){
	int i;
	if(s<=ma)return;
	if(t>m){
		ma=max(ma,s*1ll);
		return;
	}
	for(i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			b[t]=a[i].x;
			if(t==1)dfs(t+1,a[i].x);
			else dfs(t+1,s&a[i].x);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i].x;
	ma=-2e9;
	if(n<=20){
		dfs(1,0);
		cout<<ma;exit(0);
	}
	if(m==n){
		ds=a[1].x;
		for(i=2;i<=n;i++)ds=(ds&a[i].x);
		cout<<ds;exit(0);
	}
	if(m==2){
		long long p=a[1].x;
		sort(a+1,a+1+n,cmp2);
		if(a[1].x!=p)cout<<((a[1].x) and p);
		else cout<<((a[2].x) and p);
		exit(0);
	}
	s=0;
	for(i=1;i<=n;i++)if((a[i].x&(a[i].x+1))==0)s++;
	if(s==n){
		sort(a+1,a+1+n,cmp2);
		s=a[1].x;
		for(i=2;i<=m;i++)s=(s&a[i].x);
		cout<<s;exit(0);
	}
	s=0;
	for(i=1;i<=n;i++)if(a[i].x==i-1)s++;
	if(s==n||m==1){
		sort(a+1,a+1+n,cmp2);
		s=a[1].x;
		for(i=2;i<=m;i++)s=(s&a[i].x);
		cout<<s;exit(0);
	}
	cout<<0;
}