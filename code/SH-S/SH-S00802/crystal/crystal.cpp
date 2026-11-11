#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005];
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	//a[i]=i
	flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<min(n,(1+(long long)sqrt(1+8*m))/2)<<endl;
		return 0;
	}
	
	//等差
	flag=0;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			flag=1;
			break;
		}
	} 
	if(!flag){
		long long d=a[2]-a[1];
		cout<<min(n,(d+(long long)sqrt(d*d+8*d*m))/(2*d))<<endl;
		return 0;
	}
	
	//正常情况
	for(int i=2;i<=n;i++){
		a[i]+=a[i-1];
	}
	int l=1,r=1,ans=1;
	for(r=1;r<=n;r++){
//		cout<<a[r]-a[r-1]<<' '<<a[r]-a[l-1]<<endl;
		while((a[r]-a[r-1])*(r-l+1)-(a[r]-a[l-1])>m){
			++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
