#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,ans;
long long a[N],b[N];
bool check(long long mid,long long qwe){
	if(a[qwe]*(qwe-mid+1)-(b[qwe]-b[mid-1])<=m){
		return 1;
	}else{
		return 0;
	}
}
long long find(long long er){
	long long L=1,R=er,MID;
	while(L<=R){
		MID=(L+R)/2;
		if(check(MID,er)){
			R=MID-1;
		}else{
			L=MID+1;
		}
	}
	return L;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,i-find(i)+1);
	}
	cout<<ans;
	return 0;
}