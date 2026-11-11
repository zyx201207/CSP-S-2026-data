#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;

long long a[MAXN];
long long m;
long long v[MAXN];
int n;
int ans;

bool cmp(long long a,long long b){return a<b;}

int dfs(int now,long long value,long long num){
	if(value<0) return 0;
	if(now>n) return 0;
	int _n=1;
	_n+=dfs(now+1,value-v[now]*num,num+1);
	return _n;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	v[n]=1e12+10;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++) v[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		int num=0;
		int _n=0;
		long long value=m;
		for(int j=1;j<=n;j++){
			if(value<0) break;
			value-=v[j]*num;
			num++,_n++;
		}
		ans=max(ans,_n);
	}
	cout<<ans;
	return 0;
}
