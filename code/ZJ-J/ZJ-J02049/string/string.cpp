#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0; i<n; ++i) cin>>a[i]>>c[i];
	
	int hr=a[0],tr=a[n-1],hp=0,tp=n-1;
	long long ans=0;
	while(hp<tp){
		if(hr<tr){
			ans+=(c[hp]!=c[tp])*hr;
			tr-=hr;
			++hp;
			hr=a[hp];
		}else if(hr>tr){
			ans+=(c[hp]!=c[tp])*tr;
			hr-=tr;
			--tp;
			tr=a[tp];
		}else{
			ans+=(c[hp]!=c[tp])*hr;
			++hp;
			--tp;
			hr=a[hp];
			tr=a[tp];
		}
	}
	
	cout<<ans;
	
	return 0;
}

