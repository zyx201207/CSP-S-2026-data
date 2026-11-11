#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int he=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x=m,y=0;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int j=1;j<n;j++){
	for(int i=n-j;i>=0;i--){
		if(i==0){
			he--;
		}else if(x>=a[i]-a[i-1]){
			x-=a[i]-a[i-1]-y;
			y+=a[i]-a[i-1];
			//cout<<"*"<<x<<"*"<<" ";
			he++;
		}
	}
	x=m;
	y=0;
	ans=max(ans,he);
	//cout<<"&"<<he<<"&"<<" ";
	//cout<<ans<<" ";
	he=1;
}
	cout<<ans;
	return 0;
}
