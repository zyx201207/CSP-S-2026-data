#include<bits/stdc++.h>
//#define debug(x) cout<<#x<<'='<<x<<endl;
using namespace std;
long long n,m,a[200005],t[200005],maxn,sum,ans;
void dfs(int x,long long sum,int step){
	if(step==m){
		ans=max(ans,sum);
		return;
	}
//	debug(step);
//	debug(x);
	if(step)sum&=a[x];
	else sum=a[x];
//	debug(sum);
//	for(int j=1;j<=step;j++)cout<<'-';
	for(int i=1;i<=n;i++){
		if(i!=x){
//			printf("%lld ",a[i]);
			dfs(i,sum,step+1);
		}	
	}	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)dfs(i,0,0);
		cout<<ans;
	}else{
		a[1]=1;
		for(int i=2;i<=63;i++){
			a[i]=a[i-1]<<1;
		}
		for(int i=1,x;i<=n;i++){
			cin>>x;
			long long j=1;
			while(x){
				t[j++]+=x&1;
				x>>=1;
			}
//			cout<<j;
			maxn=max(maxn,j);
//			for(int i=1;i<=j;i++)cout<<t[i];
//			puts("");
		}
//		cout<<maxn;
//		puts("");
//		for(int i=1;i<=maxn;i++)cout<<t[i];
//		puts("");
		for(int i=1,j=maxn;i<=m;i++,j--){
//			cout<<a[i]<<endl;
			if(t[j])sum+=a[j];
		}
		cout<<sum;
	}
	return 0;
} 
