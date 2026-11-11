#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	long long l=1,r=0,l1=1,r1=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	long long ans=0;
	while(l<r){
		int m=min(a[l1],a[r1]);
		l+=m;
		r-=m;
		a[l1]-=m;
		a[r1]-=m;
		if(c[l1]!=c[r1]){
			ans+=m;
		}
		if(a[l1]==0){
			l1++;
		}
		if(a[r1]==0){
			r1--;
		}
		
	}
	cout<<ans;
	return 0;
}
