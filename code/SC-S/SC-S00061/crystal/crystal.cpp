#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
long long max_cnt=-1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	
	if(n==1){
		cout<<1;
		return 0; 
	}
	if(n<=50000){
		sort(a,a+n);
		for(int i=1;i<n;i++){
			long long sum=0,cnt=1;
			for(int j=i-1;j>=0;j--){
				sum+=a[i]-a[j];
				if(sum>m)break;
				cnt++;
			}
			max_cnt=max(max_cnt,cnt);
		}	
		cout<<max_cnt;
	}
	
	else{
		long long d=a[1]-a[0];
		long long s=0; 
		for(long long i=1;i<n;i++){
			s+=i;
			if(s*d>m){
				cout<<i;
				return 0;
			}
		}
	
		cout<<n;
		
		return 0;
	
	}
	
	return 0;
}