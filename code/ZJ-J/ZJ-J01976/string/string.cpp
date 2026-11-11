#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans=0,l=0,r;
char s[500005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	r=n-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]==a[r]){
			l++;
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
