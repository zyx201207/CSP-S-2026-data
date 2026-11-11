#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000];
bool check(long long x){
	long long h=m,c=1,f=1,mn=1e14;
	for(int l=1;l+x-1<=n;l++){
		int g=a[l+x-1]*x-(b[l+x-1]-b[l-1]);
		if(g<mn){
			mn=g;
			f=l;
		}
	}
	for(int i=f+x-2;i>=f;i--){
		h-=a[f+x-1]-a[i];
		if(h>=0)c++;
		else break;
		if(h==0)break;
	}
	if(c==x)return true;
	else return false;
}
long long find(){
	long long l=1,r=n;
	long long mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	cout<<find();
	return 0;
}
