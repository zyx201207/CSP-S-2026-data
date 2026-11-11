#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],o[200005],p[200005][55],s[55],ans;
bool vis[200005],ok;
void c(long long x,long long xb){
	long long k=-1;
	while(x){
		k++;
		if(x%2==1)	p[xb][k]=1;
		x/=2;
	}
}
long long fast_pow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y%2==1){
			y--;
			ans*=x;
		}
		y/=2;
		x*=x;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c(a[i],i);
	}
	for(long long w=50;w>=0;w--){
		long long sum=0;
		for(long long i=1;i<=n;i++){
			if(p[i][w]==1&&vis[i]==0)   sum++;
		}
		if(sum>=m){
			for(long long i=1;i<=n;i++){
				if(p[i][w]==1||vis[i]==1)   continue;
				vis[i]=1;
			}
			o[w]=1;
		}
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==0){
			if(ok==0){
				ok=1;
				ans=a[i];
			}
			else   ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}