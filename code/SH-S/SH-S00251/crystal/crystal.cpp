#include<bits/stdc++.h>
using namespace std;
long long a[500001],s[500001],b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]>=m) l=mid;
			else r=mid;
		}
		if((i-l+1)*a[i]-s[i]+s[l-1]==m) maxx=max(maxx,i-l+1);
		else maxx=max(maxx,i-r+1);
	} 
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
} 
