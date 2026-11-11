#include<bits/stdc++.h>
using namespace std;
int n;
long long a[600000];
unsigned long long s[600000],c[600000],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1);
	int v=0;
	a[0]=0;
	c[0]=0;
	a[0]=a[1];
	s[2]=a[2]-a[1];
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
		if(s[i]!=s[2])v=1;
		c[i]=c[i-1]+s[i]*(i-1);
		//cout<<"c["<<i<<"]="<<c[i]<<endl;
	}
	if(m>=c[n]){
		cout<<n;
		return 0;
	}
	if(v==0){
		int ans=0;
		int p=1;
		long long f=m/s[2];
		for(int i=n;i>=0;i--){
			if((i+1)*i*s[2]<=2*m){
				ans=i;
			}
		}
		cout<<ans+1;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i+1;j++){
			int l=j;
			int r=l+n-i-1;
			if(c[r]-(a[r]-a[l-1])*(j-1)+c[l-1]<=m){
				cout<<n-i;
				return 0;
			}
		}	
	}
	return 0;
} 