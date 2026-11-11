#include <bits/stdc++.h>
using namespace std;
const int N=600000;
long long n,m,pub;
long long a[N];
long long d[N];
bool stand=true;
//z==began,x==ans,y==cost;
bool dis(int x){
	if(d[x+1]==d[x])
		return true;
	else 
		return false;
}
long long fs1(long long x,long long y,long long z){
	if(z==n-1)
		return x;
	if((x*d[z])<(m-y)){
		x++;
		z++;
		fs1(x,y+=(x-1)*d[z-1],z);
	}
	else if((x*d[z])==(m-y)){
		if(d[z+1]==0){
			x++;
			z++;
			fs1(x,y,z);
		}
		else
			return (x+1);
}
	else
		return x;
}
long long fs2(long long x,long long y){
	y+=(x*pub);
	if(y<m){
		x++;
		fs2(x,y);
	}
	else
		return x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=-1;
	sort(a+1,a+1+n); 
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	pub=d[1];
	for(int i=1;i<n;i++){
		if(d[i]!=d[1]){
			stand=0;
			break;
		}
	}
	if(stand==0){
	for(int i=1;i<n;i++){
		int result=fs1(1,0,i);
		if(ans<result)
			ans=result;
	}
}
	else
		ans=fs2(1,0);
	cout<<ans;
}