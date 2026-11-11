#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
long long ans=0,maxx=-1;
bool ocp(long long x,long long y){
	int xx=x,yy=y,cntt=0,cnts=0;
	while(xx){
		if(xx&1){
			cntt++;
		}
		xx=xx>>1;
	}
	while(yy){
		if(yy&1){
			cnts++;
		}
		yy=yy>>1;
	}
	if(cntt>cnts){
		return 1;
	}else{
		return 0;
	}
}
bool cmp(long long a,long long b){
	return ocp(a,b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
//	cout<<ans<<" "<<a[2]<<'\n';
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 
