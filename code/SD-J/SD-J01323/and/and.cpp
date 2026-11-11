#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long ans,a[N],b[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(a[i],ans);
		return cout<<ans,0; 
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		return cout<<ans,0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		}
		return cout<<ans,0;
	}else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}

