#include<bits/stdc++.h>
using namespace std;
long long n,a[200002],mid,ans,l=1,r,rr;
char c[200002];
int main()
{
 freopen("string.in","r",stdin);
 freopen("string.out","w",stdout);
 cin>>n;
 for(int i=1;i<=n;i++){
 	cin>>a[i]>>c[i];
 	a[i]+=a[i-1];
 }
 r=n,rr=a[n];
 mid=a[n]/2+1;
 while(1)
	if(a[l]<mid){ 
		long long all=0;
		while(1){
			all+=a[r]-a[r-1];
			if(all<=a[l]-a[l-1]){
				if(c[r]!=c[l]) ans+=a[r]-a[r-1];
				r--;
			}
			else{
				all-=a[r]-a[r-1];
				a[r]-=a[l]-a[l-1]-all;
				if(c[r]!=c[l]) ans+=a[l]-a[l-1]-all;
				break;
			}
		}
		l++;
	}
	else{
		long long u=mid-a[l-1]; u--;
		long long s=a[l]-mid;
		if(rr%2==0) s++;
		if(u>s){
			long long all=0;
			while(1){
				all+=a[r]-a[r-1];
				if(all<=u-s){
					if(c[r]!=c[l]) ans+=a[r]-a[r-1];
					r--;
				}
				else break;
			}
		}
		break;
	}
 cout<<ans;
 //AKOI
 return 0;
}
