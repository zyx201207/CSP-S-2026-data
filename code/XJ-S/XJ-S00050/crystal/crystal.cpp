#include<bits/stdc++.h>
long long n,j=1;
long long m,a[1000005]={0},mhy=1,ans=1,hhh=0,cc,mm=1; 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
			scanf("%lld",&a[i]);
	}
	if(m>=1000000000){
		hhh=a[1]-a[0];
		cc=hhh;
		while(m>hhh){
			m=n-hhh;
			hhh=hhh+cc;
			mm++;
		}
		cout<<mm;
	}
	else{
		sort(a,a+n);
		for(long long i=0;i<n;i++){
			if(a[i]==a[i+1]){
				j--;
			}
			
			if(ans*(a[i+1]-a[i])<=m){
				m=m-(a[i+1]-a[i])*ans;
				for(long long q=0;q<ans;q++){
					a[q]=a[i+1];
				}
				ans++;
			}
				else{
					break;
				}
		}
		ans=ans-j;
		long long aa=ans,bb=0,count=0;
	while(aa>1){
		aa=aa/2;
		bb++;
	}
	for(long long q=bb;q>0;q--){
		for(long long i=0;i<n;i++){
			if(a[i]==a[i+1]){
				a[i]=a[i]*2;
				for(long long w=i+1;w<n;w++){
					a[w]=a[w+1];
				}
			}
			else{
				break;
			}
		}
	}
			for(long long i=0;i<mhy;i++){
		 		for(long long q=1;q<n;q++){
					if(a[0]==a[q]){
						a[0]=a[0]*2;
						a[q]=0;
						mhy++;
					}
				}
			}
		cout<<ans+mhy-1;
		
	}
		return 0;
	}
