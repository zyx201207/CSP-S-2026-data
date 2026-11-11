#include<bits/stdc++.h>
using namespace std;
long long n,m,q,ans,a[508888];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool d=1,f=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f=0;
		if(a[i]!=i) d=0;
	}
	if(n<=5000||(d==0&&f==0) ){
	for(int i=n;i>=1;i--){
		long long k,j,s,w;
		k=m;
		j=i-1;
		s=0;
		while(j>=1){
			if(s+j<ans){
				break;
			}
			w=a[i]-a[j];
			if(k-w>=0){
				k-=w;
				s++;
				j--;
			}
			else{
				break;
			}
		}
		long long q=s+1;
		ans=max(ans,q);
	}
	cout<<ans;
	return 0;	
	}
	else{
	    long long k,j,s,w;
		k=m;
		j=n-1;
		s=0;
	    while(j>=1){
			w=a[n]-a[j];
			if(k-w>=0){
				k-=w;
				s++;
				j--;
			}
			else{
				break;
			}
		}
		cout<<s+1;
		return 0;
	}
	return 0;
}
