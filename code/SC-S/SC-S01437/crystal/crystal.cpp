#include<bits/stdc++.h>
using namespace std;
long long a[100000000+10];
int n;
int m;
int hsh;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int num=0;
	int x=0x3f3f;
	
	sort(a+1,a+n+1);
	
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(a[j]<a[i]){
				num+=abs(a[i]-a[j]); 
			} 
		}
		int b=abs(num-m);
		if(min(x,b)==b&&b!=x){
			x=min(x,b);
			hsh=i; 
		}
		num=0;
	}
	
	cout<<hsh;
	
	return 0;
}
