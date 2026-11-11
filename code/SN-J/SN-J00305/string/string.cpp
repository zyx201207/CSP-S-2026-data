#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,l,r,a[200002],mid,ans,mi,an;
char c[200002];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
{
	cin>>a[i]>>c[i];
	if(c[i]==c[i-1]){
		a[i-1]+=a[i];
		n--;
		i--;
	}
}
	l=1;
	r=n;
	while(l<r){
		if(c[l]!=c[r])
		{
			if(a[l]==a[r])
			{
				ans+=a[l];
				a[l]=0;
				a[r]=0;
				l++;
				r--;
				continue;
			}
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;	
				l++;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;	
				r--;
			}
		}
		else{
			if(a[l]==a[r])
			{
				a[l]=0;
				a[r]=0;
				l++;
				r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
			else{
				a[l]-=a[r];
				a[r]=0;	
				r--;
			}
		}
		
	}
	
	cout<<ans;
	return 0;
}


 
