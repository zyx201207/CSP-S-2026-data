#include<bits/stdc++.h>
using namespace std;
long long n,a[200004],x,o,r0,ll=1;
char b[200004];
int main(){
	
	
	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>b[i];
		a[0]=1;
	    if(i==1){
	    	a[i]=x+a[i-1]-1;
		}else{
			a[i]=x+a[i-1];
		}
		o+=x;
	}
	if(o%2==1) o=o/2+1;
	else o=o/2;
	for(int i=n;i>=1;i--){
		
		if(a[i-1]<o){
			a[i+1]=a[i];
			b[i+1]=b[i];
			a[i]=o;
			break;
		}else if(a[i]>=o){
			a[i+1]=a[i];
			b[i+1]=b[i];
		}
	
		
	}
	 
	
	long long l=1,r=n+1;
	while(l<r){
		
		if(a[l+1]-a[l]<a[r]-a[r-1]){
			a[r]-=a[l+1]-a[l];
			if(b[l]!=b[r]){
				r0+=a[l+1]-a[l];
			}
			l++;
		}else if(a[l+1]-a[l]==a[r]-a[r-1]){
			if(b[l]!=b[r]){
				r0+=a[l+1]-a[l];
			}
			l++,r--;
		}else{
			a[l]+=a[r]-a[r-1];
			if(b[l]!=b[r]){
				r0+=a[r]-a[r-1];
			}
			r--;
		}
		
	}
	
		
	    cout<<r0;
	
	
	
	
	
	
	
	return 0;
}