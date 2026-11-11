#include<bits/stdc++.h>
using namespace std;
long long arr[123456];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int k=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<n;j++){
			long long l=arr[i]&arr[j];
			if(l>k){
				k=l;
			}
		}
	}
	cout<<k;
	return 0;
} 
