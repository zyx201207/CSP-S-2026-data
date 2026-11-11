#include<bits/stdc++.h>
using namespace std;

const int N=5e5+9;
long long n,m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool fa=true,fb=true;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=false;
		if(a[i]!=i) fa=false;
	}
	
	if(fa || fb){
		int x=a[2]-a[1];
		int ans=(sqrt(1+m*8/x)-1)/2;
		cout << ans+1;
		return 0;
	}
	
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=0;
		int j=i-1;
		for(;j>=1;j--){
			x+=a[i]-a[j];
			if(x>m){
				break;
			} 
		}
		ans=max(ans,i-j);
	}
	cout << ans;
	
	return 0;
}
