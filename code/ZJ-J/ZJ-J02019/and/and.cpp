#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,b[200005];
bool vis[200005];
void fs(long long step,long long zong){
	if(step>=n){
		long long sum=b[1];
		for(int i=1;i<=m;i++){
			sum=sum&b[i];
		}
		ans=max(sum,ans);
		return ;
	}
	int cur=0;
	for(long long i=step;i<=n;i++){
		if(!vis[i]){
			b[++cur]=a[i];
			vis[i]=1;
			fs(i+1,cur);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	fs(1,0);
	cout<<ans;
	return 0;
}//Trick||Treat!