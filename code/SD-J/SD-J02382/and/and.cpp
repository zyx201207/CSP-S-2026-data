#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
bool cmp(long long a,long long b){
	return a>=b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxx) maxx=a[i];
		}cout<<maxx;
		return 0;
	}long long ans=1;
	if(m==n){
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}cout<<"\n"<<ans;
	return 0;
}
