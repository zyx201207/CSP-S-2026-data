#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans,b[200005],maxx;
void dfs(int id,int cnt,long long sum){
	if(cnt==m){
		ans=max(ans,sum);
//		cout<<ans<<"       ";
//		for(int i=1;i<=cnt;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<"\n";
		return ;
	}
	if(id>n){
		return ;
	}
	dfs(id+1,cnt,sum);
	if(cnt==0){
		b[cnt+1]=a[id];
		dfs(id+1,cnt+1,a[id]);
	}
	else{
		b[cnt+1]=a[id];
		dfs(id+1,cnt+1,sum&a[id]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(n<=20){
		dfs(1,0,0);
		printf("%lld\n",ans);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]); 
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans=(ans&a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
