#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[1000000],b[1000000],l,r,x,ans;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1]; 
	}
	sort(a+1,a+1+n);
	l=1;
	for(int r=2;r<=n;r++){
		x=x+(r-l)*(a[r]-a[r-1]);
		//cout<<"x:"<<x;
		while(l<r&&x-(a[r]-a[l])>m){
			//cout<<"l:"<<l<<"r:"<<r<<"\n";
			l++;
			x-=(a[r]-a[l]);
		} 
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	//差值尽可能小（？ 
	return 0;
}
