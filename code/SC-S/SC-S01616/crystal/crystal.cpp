#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
const int N=500001;
int a[N];
bool ca,cb;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ca=true;
	cb=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=a[i]) ca=false;
	}
	for(int i=2;i<=n-1;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]) cb=false;
	}
	sort(a+1,a+n+1);
	if(ca){
		long long delta=8*m+1;
		float x=(1+sqrt(delta))/2;
		ans=ceil(x)-1;
		cout<<ans;
		fclose(stdin);fclose(stdout);
		return 0;
	}
    if(!ca&&cb){
		int k=a[2]-a[1];
		long long delta=8*m+k;
		float x=(1+(sqrt(k)/k)*(sqrt(delta)))/2;
		ans=ceil(x)-1;
		cout<<ans;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}