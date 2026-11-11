#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=INT_MIN;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long sum=0;
			//cout<<endl<<"区间:"<<endl;
			for(long long k=i;k<=j;k++){
				sum+=a[k];
				//cout<<a[k]<<" ";
			}
			//cout<<endl;
			//cout<<"区间总和:"<<sum<<"     ";
			//cout<<endl;
			if(j-i>=0){
				long long q=(sum+m)/(j-i+1);
				//cout<<"平均值:"<<q<<"     ";
				//cout<<"长度"<<j-i+1<<"     " ;
				for(long long k=i;k<=j;k++){
					if(q==a[k]){
						ans=max(ans,j-i+1);
						//cout<<"最大量:"<<ans<<endl;
					}	
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
