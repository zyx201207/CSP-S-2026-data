#include<bits/stdc++.h>
using namespace std;


long long a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long ans=0;
	long long l=1,r=n,L=a[1],R=a[n];
	while(l<r){
		long long Min=min(L,R);
		if(b[l]!=b[r]){
			ans+=Min;
			
		}
		if(L==0) l++;
		else r--;
	}
	cout<<ans;
	return 0;
}
