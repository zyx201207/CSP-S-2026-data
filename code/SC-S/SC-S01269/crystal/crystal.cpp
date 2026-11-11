#include<bits/stdc++.h>
using namespace std;
long long a[500005];

int solve(int cnt,int x){//cnt:次数 
	int ans=0;
	for(int i=x;i>0;i--){
		if(cnt-(a[x]-a[i])>=0){
			ans++;
			cnt-=a[x]-a[i];
		}
		else return ans;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int maxx=0,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		maxx=max(maxx,solve(m,i));
	}
	cout<<maxx;
	return 0;
}