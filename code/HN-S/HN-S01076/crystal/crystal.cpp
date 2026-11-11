#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	
	long long sum = 0;
	sum = a[1]-a[0];
	long long plus;
	plus = (m-sum)/2;
	a[0]=a[0]+plus+sum;
	a[1]=a[1]+plus;
	long long count=0;
	for(long long i=0;i<n;i++){
		if(a[i]==a[0]){
			count++;
		}
	}
	cout << count;
	
	return 0;
}
 
