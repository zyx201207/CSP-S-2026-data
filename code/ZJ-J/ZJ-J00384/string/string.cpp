#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N],ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int r=n;
	long long s=a[n];
	for(int l=1;l<r;l++){
		if(s>=a[l]){
			s-=a[l];
			if(c[r]!=c[l]) ans+=a[l];
			continue;
		}
		long long sum=a[l]-s;
		if(c[r]!=c[l]) ans+=s;
		r--;
		while(sum-a[r]>=0){
			if(c[r]!=c[l]) ans+=a[r];
			sum-=a[r];
			r--;
		}
		if(c[r]!=c[l]) ans+=sum;
		s=a[r]-sum;
	}
	cout<<ans;
	return 0;
}
