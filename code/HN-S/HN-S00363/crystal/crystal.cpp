#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[10056],maxx,l,r,rs;
bool zcs(int b){
	int ct=0;
	for(int i=1;i<=b;i++){
		if(a[i]<b) ct+=b-a[i]; 
	}
	return ct<=m;
}
void ef(int maxx){
	l=1,r=maxx;
	while(l<r+1){
		int mid=l+r>>1;
		if(zcs(mid)){
			l=mid+1;
			rs=mid;
		}
		else r=mid-1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxx) maxx=a[i];
	}
	sort(a+1,a+n+1);
	ef(maxx);
	for(int i=1;i<=n;i++){
		if(a[i]<=rs){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
