#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,l=0,r=0,sum=0,ans=1;
	cin>>n>>m;
	if(n<=5000){
		long long a[50010]={};
		for(int i=0;i<n;i=i+1){
			cin>>a[i];
		}
		sort(a,a+n);
		while(r<n){
			if(sum<=m){
				ans=max(ans,r-l+1);
				r=r+1;
				sum=sum+(a[r]-a[r-1])*(r-l);
			}
			else{
				l=l+1;
				sum=sum-(a[r]-a[l]);
			} 
		}
		cout<<ans;
	}
	else{
		long long a,b,mid;
		cin>>a>>b;
		if(a<b){
			swap(a,b);
		}
		r=(long long)(ceil(sqrt(2.0*m/(a-b))));
		while(l<=r){
			mid=(l+r)/2;
			if((a-b)*(mid+1)*mid/2<=m){
				l=mid+1;
				ans=l;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans; 
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
