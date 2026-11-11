#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	sum[1]=0;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+abs(a[i]-a[i-1]);
	}
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		bool f=false;
		long long cnt=0;
		for(int j=1;j<=n-mid+1;j++){
			cnt=sum[j+mid-1]-sum[j];
			if(cnt<=m){
				ans=mid;
				//cout<<sum[j+i-1]-sum[j]<<endl;
				f=true;
			}	
		}
		if(f==true){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}		
//Oct31==Dec25?
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7

