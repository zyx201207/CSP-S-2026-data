#include<bits/stdc++.h>
using namespace std;
long long a[500003],b[500003];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int l=0,r=1,ans=0;
	while(r<=n){
		m+=a[r]-a[l];
		l++;
		while(m>=0&&r<=n){
			r++;
			m-=b[r]*(r-l);
		}
		if(r==n&&m>=0){
			ans=max(ans,r-l+1);
			break;
		}
		else if(r==n){
			ans=max(ans,r-l);
			break;
		}
		m+=b[r]*(r-l);
		r--;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
