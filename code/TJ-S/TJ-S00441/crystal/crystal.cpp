#include<bits/stdc++.h>
using namespace std;
long long k[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	long long max = 0;
	for(int i = 0;i<n;i++){
		long long sum = 0;
		long long count = 1;
		for(int j = 0;j<i;j++){
			sum+=(k[i]-k[j]);
			count++;
		}
		if(m >= sum){
			if(max < count){
				max = count;
			}
		}
	}
	cout<<max;
	return 0;
} 
