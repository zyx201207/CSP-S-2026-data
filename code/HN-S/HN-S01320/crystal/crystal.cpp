#include<bits/stdc++.h>
using namespace std;
long long a[500005],m;int n;
bool pd(int w){
	long long cnt=0;
	for(int i=1;i<=w;i++){
		cnt+=(a[w]-a[i]);
	}//cout<<cnt<<" ";
	for(int i=w+1;i<=n;i++){
		if(cnt<=m)return 1;
		cnt-=(a[i-1]-a[i-w]);
		cnt+=(a[i]-a[i-1])*(w-1);
		//cout<<cnt<<" ";
	}
	if(cnt<=m)return 1;
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
	long long l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)/2;
		if(pd(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
//5 5
//1 2 6 7 9


