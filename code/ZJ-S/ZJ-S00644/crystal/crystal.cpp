#include<bits/stdc++.h>
using namespace std;
long long a[500100],b[500100],an,n,m,p=0;
long long l=1,r=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
	
		scanf("%lld",&a[i]);
		

	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=1; i<=n ;i++) b[i]=a[i]-a[i-1];
	while(l<=r && r<n){
		
		r++;
		p+=b[r]*(r-l);
		
		while(p>m && r>l){
			
			p-=(a[r]-a[l]);
			l++;
		}
	
		an=max(an,r-l+1);
		
	}
	cout<<an;
	return 0;
} 
