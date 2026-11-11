#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,count=0;;
	cin>>c>>t;
	while(t--){
		count==0;
		cin>>n>>d;
		long long arr[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		long long f=0;
		int cnt=1;
		int j=0;
		while(f<=d && j<n){
			
			if(f+arr[j]<=d){
				f+=arr[j];
				cnt++;
			}else{
				break;
			}
			j++;
			int cnt1=1;
			j=n-1;
			while(f<=d && j<=0){
				
				if(f+arr[j]<=d){
					f+=arr[j];
					cnt++;
				}else{
					break;
				}
				j--;
			}
			if(cnt==cnt1){
				count++;
			}
		}
		cout<<count<<endl;
	}
	
	
	
	
	return 0;
}
