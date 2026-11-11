#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500005];
char c[500005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];	
	}	
	int l=1,r=n;
	while(l<=r)
	{
		if(l==r){
			break;
		} 
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				l++;r--;
			}
			else{
				ans+=a[l];//Ìæ»» 
				l++;r--;
			}
		}
		else if(a[l]<a[r]){
			if(c[l]==c[r]){
			
				a[r]-=a[l];	l++;
			}
			else{
				ans+=a[l];
				
				a[r]-=a[l];l++;
			}
		}
		else{
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
} 
