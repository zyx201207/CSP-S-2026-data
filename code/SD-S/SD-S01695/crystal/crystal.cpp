#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],l=1,r=1,ans=INT_MIN,cnt=1,p=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	c[n-1]=b[n-1];
	for(int i=n-2;i>=1;i--){
		c[i]=c[i+1]+b[i];
	}
	while(r<n){
		if(l==r){
			if(b[r]<=m){
				p+=b[r]; 
				
				cnt++;
				ans=max(ans,cnt);
				r++;
				
			}
			else{
				l++;
				r++;
			}
			
		}
		else{
			p=p+cnt*(c[r]-c[r+1]);
			if(p<=m){
				cnt++;
				ans=max(ans,cnt);
				r++;
			}
			else{
				while(p>m){
					p-=(c[l]-c[r+1]);
					l++;
					cnt--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
