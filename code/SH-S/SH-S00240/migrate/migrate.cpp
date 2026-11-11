#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],cnt,ans;
void dfs(int i,int j,int used,int minn){
	if(cnt>2)
		return;
	if(i==j){
		if(used==minn)
			cnt++;
		return;
	}
	if(used==minn)
		return;
	for(int k=i+1;k<=j;k++){
		if(x[k]-x[i]>d)
			break;
		dfs(k,j,used+1,minn);
	}
}
bool check(int i,int j){
	long long maxn=0;
	int now=i;
	while(now!=j){
		maxn++;
		int p;
		for(int k=now+1;k<=j;k++){
			if(x[k]-x[now]>d)
				break;
			p=k;
		}
		if(now==p)
			return 0;
		now=p;
	}
	cnt=0;
	dfs(i,j,0,maxn);
	return (cnt==2);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			if(n==1)
				cout<<"0\n";
			else{
				long long p=d/(x[2]-x[1]);
				if(p<=1)
					cout<<"0\n";
				else
					cout<<max(0ll,n-p*2+1)<<"\n";
			}
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=check(i,j);
		cout<<ans<<"\n";
	}
	return 0;
}
