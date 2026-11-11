#include<bits/stdc++.h>
using namespace std;

long long n,a[200005];
char c[200005];
long long ans;
long long sum[200005];


long long find(long long x){
	long long l=1,r=n;
	
	while(l<=r){
		long long mid=(l+r)/2;
		
		//cout<<l<<" "<<mid<<" "<<r<<endl;
		
		if(sum[mid]>=x&&sum[mid-1]<x){
			return (mid);
		}
		
		if(sum[mid]<x){
			l=mid+1;
		}
		if(sum[mid]>x){
			r=mid-1;
		}
	}
	
	return -1;
}
/*
6
10 a
10 a
10 a
10 b
10 b
10 b
*/
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	
	sum[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<" "<<endl;
	}
	
	
	
	long long l=1,r=sum[n];
	
	
	while(l<=r){
		
		long long lindex=find(l),rindex=find(r);
		long long sl=sum[lindex]-l;
		long long sr=r-sum[rindex-1]-1;
		//cout<<find(right)<<endl;
		//cout<<l<<" "<<r<<" "<<sl<<" "<<sr<<endl;
		//break;
		
		if(sl==0||sr==0){
			if(c[lindex]!=c[rindex]){
				ans++;
			}
			l++,r--;
			
			//continue;
		}else{
			if(c[lindex]!=c[rindex]){
				ans=ans+min(sl,sr)+1;
			}
			
			l=l+min(sl,sr)+1;
			r=r-min(sl,sr)-1;
		}
		
		//cout<<l<<" "<<r<<" "<<ans<<endl;
		//system("pause");
	
		
	}
	
	//cout<<l<<" "<<r<<endl;
	
	cout<<ans<<endl;
	
	return 0;
}


//By Ge Donghan
//CSP-J P2 string
