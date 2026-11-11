#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n;
long long m;
long long a[maxn];
long long pre[maxn];
void init(){
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
}
bool check(int num){
	for(int i=num;i<=n;i++){
		long long sum=1ll*num*a[i]-(pre[i]-pre[i-num]);
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	init();
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
