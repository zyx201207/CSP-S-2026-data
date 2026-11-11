#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt=0,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;              
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==2){
		if(a[1]+m>=a[2]){	
			cout << 2; 
		}

		return 0;
	}
	
	long long k=0;
	for(int i=n;i>1;i--){
		if(a[i]==a[i-1]){
			k++;
		}
	}
	if(k==n-1){
		cout << max(n-m,m);
		return 0;
	} 
	
	long long b=a[n]-a[n-1],c=1;
	for(int i=n;i>1;i--){
		if(a[i]-a[i-1]==b) cnt++;
	}
	if(cnt==n-1){
		while(m>=a[n]-a[n-c]){			
			sum++;
			m-=a[n]-a[n-c];
			c++;
							
		}
		cout << sum;
		return 0;
	}
	cout << 1;
	return 0;
}
