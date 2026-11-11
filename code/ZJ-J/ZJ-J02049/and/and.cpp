#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	bool b[n];
	int ans=0;
	for(short j=29; j>=0; --j){
		int _m=0;
		for(int i=0; i<n; ++i){
			b[i]=a[i]/(1<<j)%2;
			_m+=b[i];
		}
		if(_m>=m){
			for(int i=0; i<n; ++i) if(!b[i]) a[i]=0;
			ans+=1<<j;
		}
	}
	cout<<ans;
	
	return 0;
}
