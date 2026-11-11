#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000010],sum,b[2000010],s;
int zjx(int x){
	int l=1,r=n,mid,y;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]<=x){
			l=mid+1;
			y=mid;
		}
		else r=mid-1;
	}
	return y;
}
void dfs(int u,bool flag){
	b[u]++;
	if(u==n)return;
	if(flag==true){
		if(zjx(a[u]+m)==n){
			if(u==s)b[n]++;
			return;
		}
		dfs(zjx(a[u]+m),true);
	}else{
		if(zjx(a[u]+m)>u){
			dfs(zjx(a[u]+m)-1,true);
		}
		dfs(zjx(a[u]+m),false);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=n;i>=1;i--){
			if(zjx(a[i]+m)!=n)break;
			if(zjx(a[i]+m)==n)s=i;
		}
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			dfs(i,false);
			for(int j=i+1;j<=n;j++){
				//cout<<i<<"-"<<j<<"--"<<b[j]<<"      ";
				if(b[j]==2)sum++;
			}
			//cout<<sum<<endl;
		}
		cout<<sum<<endl;
	}
	return 0;
} 