#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000],b[200000];
long long ma=-999;
int main(){
	freopen("crystal.in","r",stdin);
//	
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
    	b[i]=abs(a[i+1]-a[i]);
	}
	b[n]=0;
//	for(int i=1;i<=n;i++){
//    	cout<<b[i]<<" ";
//	}
//teshu
long long te=2;
	for(int i=1;i<n;i++){
    	if(b[i]==b[i+1]){
    		te++;
    		//cout<<i<<" ";
		}
	}
	//cout<<endl<<te<<endl;
	long long tz;
	if(te==n){
		long long jin=b[1];
		for(int i=1;i<=n;i++){
			long long q=i-1;
			if(((q*q+q)*jin/2)<=m){
				tz=i;
			}
		}
		cout<<tz;
		
		return 0;
	}
	//zhengwen
	int cm=0;
	for(int i=1;i<=n;i++){
		//cout<<i<<" ?"<<endl;
		long long ans=m;
		long long cnt=0;
		long long duo=0;
		long long sum=0;
		long long su=0;
		cm=0;
		for(int j=i;cm==0&&j<=n;j++){
			//cout<<i<<" ?"<<endl;
			if(a[j]==a[j+1]){
				cnt++;
				su++;
				//ans-=(su*a[j]-a[i]); 
				//cout<<1<<endl;
			}
			else if(ans>=(sum+su)*b[j-1]){
				//cout<<ans<<" "<<(sum+su)*b[j-1];
				ans-=(sum+su)*b[j-1];
				
				//cout<<ans<<" ";
				
					sum++;
				
				
//				ans-=su*(a[j]-a[i]);
//				su++;
				cnt++;
				//cout<<1<<endl;
				//cout<<ans<<" "<<sum<<" "<<su<<" "<<b[j-1]<<" "<<cnt<<endl;
			}else{
				ma=max(ma,cnt);
				cm=1;
				cnt=0;
				//cout<<2<<endl;
			}
		}
		ma=max(ma,cnt);
	}
//	if(ma==-999){
//		cout<<cnt;
//		return 0;
//	}
	cout<<ma;
//	for(int i=1;i<=n;i++){
//    	cout<<a[i]<<" "<<b[i]<<endl;
//	}
	return 0;
	
}

