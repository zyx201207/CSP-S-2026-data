#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	int cnt=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) cnt++;
	}
	if(cnt==n){
		cout<<n;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	int max=0,sum;
	for(int i=0;i<n;i++){
		for(int j=m;j>0;j--){
			a[i]+=j;
			sum=0;
			for(int k=0;k<n;k++){
				if(a[i]==a[k]) sum++;
			}
			if(sum>max)	max=sum;
			a[i]-=j;
		}
		
	}
	
	cout<<max+1;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
