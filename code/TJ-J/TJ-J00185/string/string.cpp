#include<bits/stdc++.h>
using namespace std;
long long n, ans;
const long long N=2e5+5;
long long a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1, r=n;
	while(l<r){
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r])
				ans+=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			if(c[l]!=c[r])
				ans+=a[l];
			l++;
		}
		else{
			l++;
			r--;
			if(c[l]!=c[r])
				ans+=a[l];
		}
	}
	cout<<ans;
	return 0;
}
