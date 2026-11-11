#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool f = false; 
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f = true;
		}
	}
	sort(a+1,a+n+1);
	long long ans = 0;
	for(long long i = n;i>=1;i--){
		long long cnt = 0;
		if(n<=5000){
			for(long long j = i;j>=1;j--){
				cnt+=(a[i]-a[j]);
				//cout<<a[j]<<" ";
				if(cnt>=m||j == 1){
					if(cnt>m){
						ans = max(ans,i-j);
					}else{
						ans = max(ans,i-j+1);
					}
					//cout<<endl<<"ans = "<<ans<<" cnt = "<<cnt<<" i-j = "<<i-j<<endl;
					break;
				}
			}
//			for(long long j = i;j<=n;j++){
//				cnt+=(a[j]-a[i]);
//				cout<<a[j]<<" ";
//				if(cnt>=m||j == n){
//					if(cnt>m){
//						ans = max(ans,j-i);
//					}else{
//						ans = max(ans,j-i+1);
//					}
//					cout<<endl<<"ans = "<<ans<<" cnt = "<<cnt<<" j-i = "<<j-i<<endl;
//					break;
//				}
//			}
		}else if(!f){
			
		}
	}
	cout<<ans;
} 
