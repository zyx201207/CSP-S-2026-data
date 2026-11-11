#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],pre[500010],ans;
void solve(long long num){
	long long l=1,r=num,mid;
	long long x,y;
	while(l<r){
		mid=(l+r)/2;
		x=num-mid+1;
		y=x*a[num]-(pre[num]-pre[mid-1]);
		if(y<=m){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	ans=max(ans,num-l+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
